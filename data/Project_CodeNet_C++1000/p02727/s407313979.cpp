#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// ACB160-E, 1051, 
	int x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	vector<int> p(a), q(b), r(c);
	ll ans = 0;
	rep(i, a) cin >> p[i];
	rep(i, b) cin >> q[i];
	rep(i, c) cin >> r[i];
	sort(p.rbegin(), p.rend());
	sort(q.rbegin(), q.rend());
	sort(r.begin(), r.end());
	p.resize(x); q.resize(y);
	rep(i, x) ans += p[i];
	rep(i, y) ans += q[i];
	while (1) {
		if (p.size() == 0) {
			if (q.back() < r.back()) {
				ans -= ll(q.back());
				ans += ll(r.back());
				q.pop_back();
				r.pop_back();
			}
			else break;
		}
		else if (q.size() == 0) {
			if (p.back() < r.back()) {
				ans -= ll(p.back());
				ans += ll(r.back());
				p.pop_back();
				r.pop_back();
			}
			else break;
		}
		else if (p.back() < q.back()) {
			if (p.back() < r.back()) {
				ans -= ll(p.back());
				ans += ll(r.back());
				p.pop_back();
				r.pop_back();
			}
			else break;
		}
		else {
			if (q.back() < r.back()) {
				ans -= ll(q.back());
				ans += ll(r.back());
				q.pop_back();
				r.pop_back();
			}
			else break;
		}
		if (r.size() == 0) break;
	}
	cout << ans << endl;
	return 0;
}
