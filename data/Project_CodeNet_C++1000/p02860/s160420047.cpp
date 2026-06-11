#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	string  f = "Yes";
	if (n % 2 == 0)
	{
		int i;
		for (i = 0; i < s.length() / 2; i++)
		{
			if (s.at(i) != s.at(s.length() / 2 + i))
				f = "No";
		}
	}
	else
		f = "No";
	cout << f << endl;
	
}