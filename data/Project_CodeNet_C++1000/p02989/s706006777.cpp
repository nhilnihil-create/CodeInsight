#include<bits/stdc++.h>
#define int long long
#define fo(i,n)   for(i=0;i<n;i++)
#define mod       1000000007
using namespace std;

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("ati.txt", "r", stdin);
	freopen("ato.txt", "w", stdout);
#endif

	int n, i;
	cin >> n;

	int a[n];
	fo(i, n)
	cin >> a[i];

	sort(a, a + n);
	int x = n / 2;

	if (a[x] > a[x - 1])
		cout << a[x] - a[x - 1] << endl;
	else if (a[x] == a[x - 1])
		cout << "0" << endl;
}