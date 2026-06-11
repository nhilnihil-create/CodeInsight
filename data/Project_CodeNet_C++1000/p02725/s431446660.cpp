#include<bits/stdc++.h>
#define int long long
#define fo(i,n)   for(i=0;i<n;i++)
#define mod       1000000007
using namespace std;

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("codefi.txt", "r", stdin);
	freopen("codefo.txt", "w", stdout);
#endif

	int n, k;
	cin >> k >> n;
	int a[n];
	int i;
	fo(i, n)
	cin >> a[i];
	int m = 0;

	for (int i = 0; i<n - 1; i++)
	{
		if (i == 0)
		{
			int tmp = a[i] + k - a[n - 1];
			m = max(tmp, m);
		}
		else
		{
			m = max(m, a[i + 1] - a[i]);
		}
	}
	int mm=m;
	cout << k-mm << endl;
}