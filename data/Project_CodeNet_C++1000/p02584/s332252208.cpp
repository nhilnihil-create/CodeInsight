#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;

	int x, k, d;
	cin >> x >> k >> d;
	x = abs(x);
	int st = min(k, x / d);
	k -= st;
	x -= st * d;
	if (k & 1)
		cout << d - x;
	else
		cout << x;
	return 0;
}