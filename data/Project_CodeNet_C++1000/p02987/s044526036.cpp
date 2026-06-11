#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	string s;
	int flg = 0;
	cin >> s;
	if (s.at(0) == s.at(1) && s.at(0) != s.at(2))
	{
		if (s.at(2) == s.at(3))
		{
			flg = 1;
		}
	}
	else if (s.at(0) == s.at(2) && s.at(0) != s.at(1))
	{
		if (s.at(1) == s.at(3))
		{
			flg = 1;
		}
	}
	else if (s.at(0) == s.at(3) && s.at(0) != s.at(1))
	{
		if (s.at(1) == s.at(2))
		{
			flg = 1;
		}
	}
	if (flg == 0)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}