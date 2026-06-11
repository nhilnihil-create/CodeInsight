#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
typedef long long ll;
typedef long double ld;
int n, a[N], l1[N], l2[N], r1[N], r2[N];
deque<int> dq;
ll sz(int l, int r) { return r - l + 1; }
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n; for (int i = 1; i <= n; ++i) cin >> a[i];
	a[0] = a[n + 1] = N;
	dq.push_back(0); dq.push_back(0);
	for (int i = 1; i <= n; ++i) {
		while (!dq.empty() && a[i] > a[dq.back()]) dq.pop_back();
		//int k = dq.size();
		l1[i] = dq.back();
		dq.push_back(i);
	}
	while (!dq.empty()) dq.pop_back();
	dq.push_front(n+1); dq.push_front(n+1);
	for (int i = n; i >= 1; --i) {
		while (!dq.empty() && a[i] > a[dq.front()]) dq.pop_front();
		//int k = dq.size();
		r1[i] = dq.front();
		dq.push_front(i);
	}
	for (int i = 1; i <= n; ++i) {
		int x = max(0, l1[i] - 1);
		while (a[i] > a[x]) x = l1[x];
		l2[i] = x;
	}
	for (int i = n; i >= 1; --i) {
		int x = min(n + 1, r1[i] + 1);
		while (a[i] > a[x]) x = r1[x];
		r2[i] = x;
	}

	ll ans = 0LL;
	for (int i = 1; i <= n; ++i) {
		ll L2 = sz(l2[i] + 1, l1[i]), R1 = sz(i, r1[i] - 1),
			L1 = sz(l1[i] + 1, i), R2 = sz(r1[i], r2[i] - 1);
		//cout << L2 << " " << R1 << " " << L1 << " " << R2 << endl;
		ans += L2 * R1 * a[i];
		ans += L1 * R2 * a[i];
	}
	cout << ans << endl;
}