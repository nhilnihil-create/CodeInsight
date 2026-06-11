#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
//#include <cstdlib>
//#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <set>
using namespace std;

#define MAXNUM 250000

int main(void){

	bool nonPrimeMap[MAXNUM] = { false };
	int count = 0;
	int result = 0;

	for (int i = 4;  i < MAXNUM; i = i + 2){
		nonPrimeMap[i] = true;
	}

	for (int i = 3; i < MAXNUM; i = i + 2){
		for (int j = 2; i * j < MAXNUM; j++){
			nonPrimeMap[i * j] = true;
		}
	}

	nonPrimeMap[1] = true;

	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0) break;

		int count = 0;

		for (int i = n + 1; i <= n * 2; i++){
			if (!nonPrimeMap[i]) count++;
		}

		cout << count << endl;

	}


	return 0;
}