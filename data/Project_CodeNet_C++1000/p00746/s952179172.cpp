#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#define pi 3.14159
using namespace std;

 
int main(){
	while(1) {
		int N;
		cin >> N;
		if(N == 0) break;
		int a[401][401];
		for(int j = 0; j < 401; j++) {
				for(int k = 0; k < 401; k++) {
					a[j][k] = -1;
				}
		}
		int y = 200, x = 200;
		a[200][200] = 0;
		for(int i = 0; i < N-1; i++) {
			int n, d;
			cin >> n >> d;
			for(int j = 0; j < 401; j++) {
				for(int k = 0; k < 401; k++) {
					if(a[j][k] == n) {
						y = j;
						x = k;
						break;
					}
				}
			}
			if(d == 0) a[y][x - 1] = i+1;
			if(d == 1) a[y + 1][x] = i+1;
			if(d == 2) a[y][x + 1] = i+1;
			if(d == 3) a[y - 1][x] = i+1;
		}

		int maxW = 0, maxH = 0, minW = 401, minH = 401;
		for(int j = 0; j < 401; j++) {
			for(int k = 0; k < 401; k++) {
				if(a[j][k] >= 0) {
					x = k;
					if(x > maxW) maxW = x;
					if(x < minW) minW = x;
				}
				if(a[k][j] >= 0) {
					y = k;
					if(y > maxH) maxH = y;
					if(y < minH) minH = y;
				}
			}
		}
		int W = maxW - minW + 1, H = maxH - minH + 1;;
		cout << W << " " << H <<endl;
	}
				


	return 0;
}