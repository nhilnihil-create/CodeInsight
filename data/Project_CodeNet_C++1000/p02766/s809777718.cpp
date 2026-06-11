#include <bits/stdc++.h>
#define cina(a, n) for (int i = 0; i < n; ++i){ cin >> a[i]; }
#define ll long long
#define ld long double

using namespace std;

int main () {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n, k;
	cin >> n >> k;
	int ans = 0;
	while (n) {
		n /= k;
		ans++;
	}
	cout << ans;
	return 0;
}