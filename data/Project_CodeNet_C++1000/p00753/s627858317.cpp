//#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
//#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <set>
using namespace std;

int main(void){

	bool check[260000] = { false };
	check[1] = true;

	for (int i = 2; i < 260000; i++){
		for (int j = 2; i*j < 260000; j++){
			check[i*j] = true;
		}
	}

	long int n;

	while (scanf("%d", &n) != EOF){
		if (n == 0) break;
		int count = 0;

		for (long int i = n + 1; i <= 2 * n; i++){
			if (!check[i]) count++;
		}

		cout << count << endl;
	}

	return 0;
}

/*
for(i=0;i<N;i++){
cin >> X[i];
}


for(i=0;i<N;i++){
for(j=0;j<N;j++){
cin >> X[i][j];
}
}
*/