#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	string s;
	cin >> s;
	int a = 0;
	if (s == "SUN")
		a = 7;
	if (s == "MON")
		a = 6;
	if (s == "TUE")
		a = 5;
	if (s == "WED")
		a = 4;
	if (s == "THU")
		a = 3;
	if (s == "FRI")
		a = 2;
	if (s == "SAT")
		a = 1;
	cout << a << endl;
}