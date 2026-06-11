#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, d[150], ans;
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ans = 0;
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> d[i];
	for(int i = 0; i < n-1; ++i) {
		for(int j = i+1; j < n; ++j) {
			ans += d[i]*d[j];
		}
	}
	cout << ans;
}