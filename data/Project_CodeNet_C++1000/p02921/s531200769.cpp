#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define int long long

string a, b;
int32_t main() {
	int ans = 0;
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> a >> b;
	for(int i = 0; i < 3; ++i) {
		if (a[i] == b[i]) ++ans;
	}
	cout << ans;
}