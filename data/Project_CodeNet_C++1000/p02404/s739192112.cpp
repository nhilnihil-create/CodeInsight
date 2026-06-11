#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
	int h = 0, w = 0;

	while (1){
		cin >> h >> w;
		if (h == 0 && w == 0){ break; }
		for (int i = 0; i < h;i++){
			for (int s = 0; s < w; s++){
				if (i == 0 || i == h-1  || s == 0 || s == w-1){printf("#");}
				else{ printf("."); }
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}