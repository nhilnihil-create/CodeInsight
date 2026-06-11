#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define int long long

int n, p[100], ans;
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ans = 0;
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> p[i];
	for(int i = 1; i < n-1; ++i) {
		if ((p[i] < p[i+1] && p[i] > p[i-1]) || (p[i] > p[i+1] && p[i] < p[i-1])) {
			++ans;
		}
	}
	cout << ans;
}