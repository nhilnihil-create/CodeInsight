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
	int i;
	int cnt = 0, a = 0;
	for (i = 0; i < n; i++)
	{
		if (s.at(i) == 'C')
		{
			if (a == 2)
			{
				cnt++;
				a = 0;
			}
			else
				a = 0;
		}
		else if (s.at(i) == 'B')
		{
			if (a == 1)
				a++;
			else
				a = 0;
		}
		else if (s.at(i) == 'A')
			a = 1;
	}
	cout << cnt << endl;
}