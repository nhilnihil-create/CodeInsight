//============================================================================
// Name        : HelloCPP.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

	int H,W;
	while(1){
		cin >> H >> W;

		if (H == 0 && W == 0) break;

		for(int i = 0; i < H; i++ ){	//gyou
			for(int j = 0; j < W; j++){ // retsu
				if((i == 0)|(i == H-1)| (j == 0)|(j == W-1)){
					printf("#");
				}else{
					printf(".");
				}
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}