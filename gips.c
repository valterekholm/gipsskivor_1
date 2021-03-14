#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Jag hittade ett fel, då min vägg om 270 cm ska rymma endast 3 skivor...
//Därför byter jag ut vissa variabler till heltal - och mäter i millimeter

int main(){

	int skiv_hojd[] = {1800, 2400, 2500, 2900};
	int ant_skiv_mod = 4;//modeller
	int tak_hojd = 2800;
	int vagg_bredd = 2700;
	int skiv_bredd = 900;//millimeter
	int least_waste = 1000000;
	int least_waste_height = 0;
	int vbs = (int) ceil(vagg_bredd / skiv_bredd);//Hur många skivor är väggen bred

	printf("%d \n", (int) ceil(2700/900));


	printf("Program för gips \n\n");
	printf("Väggen: \n");
	printf("\tbredd: %d \n", vagg_bredd);
	printf("\thöjd: %d \n", tak_hojd);
	
	int scount;
	for(scount = 0; scount < ant_skiv_mod; scount++){
		int s_h = skiv_hojd[scount];
		printf("Kollar skiva %d \n", s_h);
		int saknad_hojd = tak_hojd - s_h;
		printf("Saknad höjd: %d \n", saknad_hojd);
		int mavf = 0; //Modellens avfall

		if(saknad_hojd <= 0){
			mavf = abs(saknad_hojd * vbs);
		}
		else{
			printf("Väggens bredd i skivor är %d \n", vbs);
			int avskb = vbs;
			int hgsr = s_h / saknad_hojd;//hela gånger som saknad_hojd ryms i s_h
			printf("Hela gånger som saknad_höjd ryms i skiva: %d \n", hgsr);
			int kompl_sk = 0;
			int avfall = 0;
			int hole_count = vbs;
			int resterande_skiva = s_h;

			while(hole_count){
				printf("Fyll ett hål \n");
				hole_count--;
				resterande_skiva = resterande_skiva - saknad_hojd;
				if(resterande_skiva < saknad_hojd){
					printf("Skiva förbrukad \n");
					mavf += resterande_skiva;
					resterande_skiva = s_h;
				}
			}
			if(resterande_skiva != s_h){
				printf("Resterande skiva är inte som skivhöjd!!! \n");
				mavf += resterande_skiva;
			}

		}


		printf("Denna skivmodell har avfall: %d \n", mavf);
		if(mavf < least_waste){
			printf("Hittade nytt sparsamhets bottenvärde, %d \n", mavf);
			least_waste = mavf;
			least_waste_height = s_h;
		}
		printf("---------\n");
	}

	printf("Mest sparsamma värdet: %d, hade skivmodell %d \n", least_waste, least_waste_height);

	return 0;
}
