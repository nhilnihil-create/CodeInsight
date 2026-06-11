#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
	while(1){
		int H, W;
		cin >> H >> W;
		if(H == 0 && W == 0) break;

		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				printf("#");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}