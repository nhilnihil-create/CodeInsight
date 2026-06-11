#include<iostream>
#include<string>
#include<stdio.h>
#include<cctype>
#include<algorithm>
#include<climits>
#include<cmath>
#include<map>
#include<vector>
#define INF INT_MAX
using namespace std;

int X;

int main(){
	cin >> X;
	if (X < 600 && X >= 400){
		cout << 8 << endl;
	}
	if (X < 800 && X >= 600){
		cout << 7 << endl;
	}
	if (X < 1000 && X >= 800){
		cout << 6 << endl;
	}
	if (X < 1200 && X >= 1000){
		cout << 5 << endl;
	}
	if (X < 1400 && X >= 1200){
		cout << 4 << endl;
	}
	if (X < 1600 && X >= 1400){
		cout << 3 << endl;
	}
	if (X < 1800 && X >= 1600){
		cout << 2 << endl;
	}
	if (X < 2000 && X >= 1800){
		cout << 1 << endl;
	}
	
	return 0;
}