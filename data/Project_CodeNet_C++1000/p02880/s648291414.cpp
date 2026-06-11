#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int n;
	cin >> n;
	int i, j;
	string s = "No";
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			if (n == i * j)
				s = "Yes";
		}
	}
	cout << s << endl;
	
}