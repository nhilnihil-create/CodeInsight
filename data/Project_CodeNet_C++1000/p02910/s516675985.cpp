#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	string s;
	cin >> s;
	int i;
	string a = "Yes";
	for (i = 0; i < s.length(); i++)
	{
		if (i % 2 == 1 && s.at(i) == 'R')
			a = "No";
		if (i % 2 == 0 && s.at(i) == 'L')
			a = "No";
	}
	cout << a << endl;
}