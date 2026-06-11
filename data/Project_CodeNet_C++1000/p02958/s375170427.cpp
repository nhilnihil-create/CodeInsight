#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int n;
	cin >> n;
	vector<int>p(n), q(n);
	int i;
	for (i = 0; i < n; i++)
	{
		cin >> p.at(i);
		q.at(i) = p.at(i);
	}
	int cnt = 0;
	sort(q.begin(), q.end());
	for (i = 0; i < n; i++)
	{
		if (p.at(i) != q.at(i))
			cnt++;
	}
	if (cnt == 0 || cnt == 2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}