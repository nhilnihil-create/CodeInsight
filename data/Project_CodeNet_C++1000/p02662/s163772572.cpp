#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 998244353;

int n, s;
int a[3001], f[3001];

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;
	for (int i = 1; i <= n; i++)	
		cin >> a[i];
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = s; j >= 0; j--)
		{
			(f[j] *= 2) %= mod;
			if (j >= a[i])
				(f[j] += f[j - a[i]]) %= mod;	
		}
	cout << f[s];
}