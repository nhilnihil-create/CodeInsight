#include <cstdio>

#define INFONUM 4
#define HOUSENUM 4
#define FLOORNUM 3
#define ROOMNUM 10

int main()
{
	int n;
	scanf("%d", &n);

	int info[n][INFONUM];
	int buff[HOUSENUM][FLOORNUM][ROOMNUM];

	/*CLEAR ARRAY "buff"*/
	for(int j = 0; j < HOUSENUM; j++){
		for(int k = 0; k < FLOORNUM; k++){
			for(int l = 0; l < ROOMNUM; l++)
				buff[j][k][l] = 0;
		}
	}	

	for(int i = 0; i < n; i++){
		for(int j = 0; j < INFONUM; j++){
			scanf("%d", &info[i][j]);
		}
	}

	for(int i = 0; i < n; i++){

		for(int j = 0; j < HOUSENUM; j++){
			for(int k = 0; k < FLOORNUM; k++){
				for(int l = 0; l < ROOMNUM; l++){

					if(j == info[i][0] - 1 && k == info[i][1] - 1 && l == info[i][2] - 1)
						buff[j][k][l] += info[i][3];
				}
			}
		}
	}

	for(int i = 0; i < HOUSENUM; i++){

		for(int j = 0; j < FLOORNUM; j++){
			for(int k = 0; k < ROOMNUM; k++){
				printf(" %d", buff[i][j][k]);
			}
			printf("\n");
		}

		if(i != HOUSENUM - 1){
			for(int j = 0; j < 20; j++)
				printf("#");
			printf("\n");
		}
	}

	return 0;
}