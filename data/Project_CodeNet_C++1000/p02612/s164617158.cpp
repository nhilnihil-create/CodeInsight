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

	int n;
	cin >> n;
	int rem = n % 1000;
	if (rem) {
		if (rem > 500)
			cout << (n / 1000) * 1000 + 1000 - n;
		else
			cout << 1000 - rem;
	} else {
		cout << 0;
	}
	return 0;
}