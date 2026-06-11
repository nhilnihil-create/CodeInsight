#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int x;
	cin >> x;
	int a,b=0;
	a = x / 500;
	x = x - (a * 500);
	b += a * 1000;
	a = x / 5;
	b += a * 5;
	cout << b << endl;
} 