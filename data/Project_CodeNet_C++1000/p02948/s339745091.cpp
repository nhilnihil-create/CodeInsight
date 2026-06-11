#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define pii pair <int, int>
#define all(vv) (vv).begin(), (vv).end()
#define time cerr << '\n' << (double)clock()/CLOCKS_PER_SEC << '\n'; return 0

int n, m;
pii ab[100100];
priority_queue <int, vector <int>, greater <int>> pq;

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> ab[i].first >> ab[i].second;
	}
	sort(ab, ab + n, greater<pii>());
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		int r = ab[i].second;
		if (pq.size() + ab[i].first <= m) {// fits the max days 
			ans += r;
			pq.push(r);
		} 
		else if (pq.size() && pq.top() < r) {// can fit cuz less days (due to sort)
			ans -= pq.top();                 // check the one with most output
			ans += r;
			pq.pop();
			pq.push(r);
		}
	}
	cout << ans;
	time;
}