#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

int a[N], b[N];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	auto pre = [&](int i) {
		return (i + n - 1) % n;
	};
	auto nxt = [&](int i) {
		return (i + 1) % n;
	};
	priority_queue<pi> pq;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		if(b[i] < a[i]) return cout << -1 << endl, 0;
		if(b[i] > a[i]) pq.push({b[i], i});
	}
	while(pq.size()) {
		int i = pq.top().S; pq.pop();
		if(b[i] - (b[pre(i)] + b[nxt(i)]) < a[i]) return cout << -1 << endl, 0;
		int cnt = (b[i] - a[i]) / (b[pre(i)] + b[nxt(i)]);
		b[i] -= cnt * (b[pre(i)] + b[nxt(i)]);
		ans += cnt;
		if(b[i] > a[i]) {
			pq.push({b[i], i});
		}
	}
	cout << ans << endl;
	

}




