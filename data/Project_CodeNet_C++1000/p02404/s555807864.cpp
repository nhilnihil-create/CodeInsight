#include <iostream>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;

int H, W;
vector<long> v;
int main(){

	while (true){
		cin >> H >> W;
		if (H + W == 0)break;

		for (int y = 0; y < H; ++y){
			for (int x = 0; x < W; ++x){
				if (y > 0 && y < H - 1 && x > 0 && x < W - 1){
					cout << ".";
				}
				else{
					cout << "#";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	
	return 0;
}