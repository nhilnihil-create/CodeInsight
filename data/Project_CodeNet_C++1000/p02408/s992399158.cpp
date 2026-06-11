#include <stdio.h>

#include <iostream>
using namespace std;
#include <stdio.h>
int main()
{
	int n, i, j, card[4][14] = { 0 }, ans[52], x;
	char X;
	cin >> n;
	for (i = 0; i<n; i++){
		cin >> X >> x;
		switch (X){
		case 'S':  card[0][x] = 1; card[0][0]++; break;
		case 'H':  card[1][x] = 1; card[1][0]++; break;
		case 'C':  card[2][x] = 1; card[2][0]++; break;
		case 'D':  card[3][x] = 1; card[3][0]++; break;
		}
	}
	for (i = 0; i<4; i++){
		if (card[i][0]<13){
			for (j = 1; j <= 13; j++){
				if (card[i][j] == 0){
					switch (i){
					case 0: printf("S"); break;
					case 1: printf("H"); break;
					case 2: printf("C"); break;
					case 3: printf("D"); break;
					}
					printf(" %d\n", j);
				}
			}
		}
	}
}