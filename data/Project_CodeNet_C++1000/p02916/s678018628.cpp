#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define PI 3.14159265358979
#define MOD 1000000007 // = 10^9 + 7

using namespace std;
using ll = long long;


void solve()
{
	int n, b, ans = 0;
	cin >> n;
	vector<int> a(n), c(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i){cin >> b; ans += b; }
	for(int i = 0; i < n; ++i) cin >> c[i];

	for(int i = 1; i < n; ++i)
	{
		if (a[i - 1] + 1 == a[i])
		{
			ans += c[a[i - 1] - 1];
		}
	}
	cout << ans;
}

int main()
{
	fastio;
	solve();

	return 0;
}