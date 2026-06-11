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

	int n, k;
	cin >> n >> k;

	cout << min(n % k, k - n % k) << endl;
}