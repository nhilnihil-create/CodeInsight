#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int h, n;
	cin >> h >> n;
	int i;
	vector<int>a(n);
	for (i = 0; i < n; i++)
	{
		cin >> a.at(i);
		h -= a.at(i);
		if (h <= 0)
		{
			break;
		}
	}
	if (h <= 0)
		cout << "Yes" << endl;
	else
		cout << "No"<<endl;

	
}