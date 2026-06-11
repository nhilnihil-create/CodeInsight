#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define int long long

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int ans = 0;
	int n; cin >> n;
	for(int i = 1; i <= n; ++i) {
		string a = to_string(i);
		if (a.length() % 2 == 1) ++ans;
	}
	cout << ans;
}