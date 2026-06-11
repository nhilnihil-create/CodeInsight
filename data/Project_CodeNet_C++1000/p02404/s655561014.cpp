#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
	int W, H;

	while(1){

		cin >> H >> W;

		if(W == 0 && H == 0) break;

		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				if((i == 0) || (i == H - 1) || (j == 0) || (j == W - 1)) printf("#");
				else printf(".");
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}