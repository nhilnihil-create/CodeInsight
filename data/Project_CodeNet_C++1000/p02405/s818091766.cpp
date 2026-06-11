//============================================================================
// Name        : ITP_1_5_C.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int H,W;
	do {
		cin >> H >> W;
		if(H==0 && W==0) break;
		for(int j=0;j<H;++j) {
			for(int i=0;i<W;++i){
				if((i+j)%2==0) {
					printf("#");
				} else {
					printf(".");
				}
			}
			printf("\n");
		}
		printf("\n");
	} while(1);
	return 0;
}