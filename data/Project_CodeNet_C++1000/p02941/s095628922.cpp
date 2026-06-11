#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>


using namespace std;

#define REP(i, n) for(ll i = 0;i < n;i++)
#define REPR(i, n) for(ll i = n;i >= 0;i--)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define REPO(i, n) for(ll i = 1;i <= n;i++)
#define ll long long
#define INF (ll)1 << 60
#define MINF (-1 * INF)
#define ALL(n) n.begin(),n.end()
#define MOD (ll)1000000007
#define P pair<ll, ll>


ll n, a[210000], b[210000], ans;
bool ok = true;
priority_queue<P> q;

int main() {
	cin >> n;
	REP(i, n) cin >> a[i];
	REP(i, n) {
		cin >> b[i];
		if (a[i] > b[i])ok = false;
		if (a[i] < b[i])q.push(P(b[i], i));
	}
	while (!q.empty()) {
		P tp = q.top();
		q.pop();
		ll i = tp.second;
		ll now = b[(i - 1 + n) % n] + b[(i + 1) % n], ax = (b[i] - max(a[i], now) + now - 1) / now;
		if (now >= b[i])continue;
		b[i] -= ax * now;
		if (a[i] > b[i]) {
			ok = false;
			break;
		}
		if (a[i] < b[i]) q.push(P(b[i], i));
		ans += ax;
	}
	REP(i, n) {
		if (a[i] != b[i])ok = false;
	}
	if (!ok)ans = -1;
	cout << ans << endl;
}
