#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	a = a - b;
	c = c - a;
	if (c <= 0)
		cout << 0 << endl;
	else
		cout << c << endl;
}