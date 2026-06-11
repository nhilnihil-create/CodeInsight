#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <iomanip>
#include <utility>
#define INF 1000000009
#define LINF 1000000000000000009
#define double long double
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> PP;
typedef pair<ll, double> PD;
//ll mod = 1000000007;
ll mod = 998244353;

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n), b(n);
	ll sum = 0, goal = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		goal += a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		sum += b[i];
	}
	priority_queue<P> pq;
	ll cnt = 0;
	for (int i = 0; i < n; i++) pq.push(P(b[i], i));
	while (sum > goal && !pq.empty()) {
		P p = pq.top();
		pq.pop();
		ll ps = p.second;
		sum -= b[ps];
		ll dis = b[(ps + 1) % n] + b[(ps + n - 1) % n];
		ll mov = (b[ps] - a[ps]) / dis;
		if (mov == 0 && b[ps] != a[ps]) {
			cout << -1 << endl;
			return 0;
		}
		b[ps] -= mov * dis;
		cnt += mov;
		sum += b[ps];
		if (mov != 0) pq.push(P(b[ps], ps));
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << cnt << endl;
}