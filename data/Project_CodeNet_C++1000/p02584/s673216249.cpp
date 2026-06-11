#include <bits/stdc++.h>
#define maxN 1000000
using namespace std;
const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	long long x, k, d, ans;
	cin >> x >> k >> d;

	x = abs(x);
	if (d >= x) {
		if (k & 1)
			ans = d - x;
		else
			ans = x;
	}
	else {
		if (x / d >= k)
			ans = x - d * k;
		else {
			k = k - x / d;
			x = x - d * (x / d);
			if (d >= x) {
				if (k & 1)
					ans = d - x;
				else
					ans = x;
			}

		}
	}

	cout << ans << endl;

}
