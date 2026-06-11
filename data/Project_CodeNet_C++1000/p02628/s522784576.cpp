#include <bits/stdc++.h>
#define cina(a, n) for (int i = 0; i < n; ++i){ cin >> a[i]; }
#define ll long long
#define ld long double

using namespace std;

int main () {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	int p[n];
	cina(p, n);
	sort(p, p+n);
	int ans = 0;
	for (int i = 0; i < k; ++i) {
		ans += p[i];
	}
	cout << ans;
	return 0;
}