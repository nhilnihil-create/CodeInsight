#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 1<<20;
int n;
int l[maxn], r[maxn], raw[maxn], dp[maxn];
vector<int> el[maxn];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int x, L, i = 0; i < n; i++) {
		cin >> x >> L;
		tie(x, L) = tuple<int, int>{x-L, x+L};
		raw[2*i+1] = x, raw[2*i+2] = L;
		l[i] = x, r[i] = L;
	}
	raw[0] = -(1<<30);
	sort(raw, raw + 2*n + 1);
	for(int i = 0; i < n; i++) {
		l[i] = lower_bound(raw, raw + 2*n + 1, l[i]) - raw;
		r[i] = lower_bound(raw, raw + 2*n + 1, r[i]) - raw;
		el[r[i]].push_back(l[i]);
	}
	for(int i = 0; i <= 2*n; i++) {
		if(i) dp[i] = dp[i-1];
		for(auto j : el[i]) dp[i] = max(dp[i], dp[j] + 1);
	}
	cout << dp[2*n];
}
