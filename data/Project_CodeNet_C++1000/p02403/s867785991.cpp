#include <iostream>
using namespace std;
#include <stdio.h>
int main()
{
	int HW[10000][2], i = 0, j, l, k;
	while (1){
		cin >> HW[i][0] >> HW[i][1];
		if (HW[i][0] == 0 && HW[i][1] == 0)break;
		i++;
	}
	for (j = 0; j<i; j++){
		for (l = 0; l<HW[j][0]; l++){
			for (k = 0; k<HW[j][1]; k++){
				printf("#");
			}
			printf("\n");
		}
		printf("\n");
	}
}