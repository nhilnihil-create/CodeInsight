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
	int f = 1;

	int n;
	n = s.length();
	for (i = 0; i < n; i++)
	{
		if (s.at(i) != s.at(s.length() - 1 - i))
			f = 0;
	}
	if (f == 1)
	{
		for (i = 0; i < (n - 1) / 2; i++)
		{
			if (s.at(i) != s.at((n - 1) / 2 - 1 - i))
				f = 0;
		}
	}
	if (f)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}