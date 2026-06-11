#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int k, x;
	cin >> k >> x;
	int i;
	i = x - k + 1;
	while (i <= x + k - 1)
	{
		
		cout << i;
		i++;
		if (i > x + k - 1)
		{
			break;
		}
		cout << " ";
	}
	cout << endl;
}