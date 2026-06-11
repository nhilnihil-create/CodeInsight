// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

void solve(int a[], int b[], int ret[]){
	// ret[0] = ヒット数, ret[1] = ブロー数
	for (int i = 0; i < 4; i++){
		if (a[i] == b[i])	ret[0]++;
		else{
			for (int j = 0; j < 4; j++){
				if (b[i] == a[j])
					ret[1]++;
			}
		}
	}
}

int main(){
	int a[4], b[4];
	int ret[2] = {};

	while (cin >> a[0] >> a[1] >> a[2] >> a[3], !cin.eof()){
		for (int i = 0; i < 4; i++)	cin >> b[i];
		ret[0] = 0; ret[1] = 0;
		solve(a, b, ret);
		cout << ret[0] << " " << ret[1] << endl;
	}
	return 0;
}