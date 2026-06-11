#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int n, p[100001], pos[100001];
	cin >> n;
	rep(i, n) cin >> p[i + 1];
	for(int i = 1; i <= n; i++) {
		pos[p[i]] = i;
	}
	set<ll> s{0, n+1};
	ll ans = 0;
	for(int i = n; i >= 1; i--) {
		int ps = pos[i];
		s.insert(ps);
		if (i == n) continue;
		auto it11 = s.find(ps), it21 = it11;
		if (it11 != s.begin()) it11--;
		auto it12 = it11;
		if (it12 != s.begin()) it12--;
		it21++;
		if (it21 == s.end()) it21--;
		auto it22 = it21;
		it22++;
		if (it22 == s.end()) it22--;
		ans += i * (*it11 - *it12) * (*it21 - ps);
		ans += i * (ps - *it11) * (*it22 - *it21);
	}
	cout << ans << endl;
}
