#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define int long long

int n, a[100100], dp[100100];
vector <int> v;
int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 1; i < n; ++i) {
		if (a[i-1] >= a[i]) dp[i] = dp[i-1]+1;
		else dp[i] = 0;
	}
	cout << *max_element(dp, dp+n);
}