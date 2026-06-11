#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI acos(-1.0)
#define test() int t; cin>>t; while(t--)
#define ll long long int
int mod = 1e9 + 7;
int main()
{
	IOS;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	vector<ll> prefA(n + 1), prefB(m + 1);
	prefA[0] = 0;
	prefB[0] = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		prefA[i] = prefA[i - 1] + a[i - 1];
	}
	for (int i = 1; i <= m; i++) {
		prefB[i] = prefB[i - 1] + b[i - 1];
	}
	int j = m;
	for (int i = 0; i <= n; i++) {
		if (prefA[i] > k) break;
		while (prefB[j] > k - prefA[i])	j--;
		ans = max(ans, i + j);
	}
	cout << ans << endl;
	return 0;
}
