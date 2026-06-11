#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int n,k;
	cin >> n>>k;

	vector<int>h(n);
	int i;
	int cnt = 0;
	for (i = 0; i < n; i++)
	{
		cin >> h.at(i);
		if (h.at(i) >= k)
			cnt++;
	}
	cout << cnt << endl;
	
}