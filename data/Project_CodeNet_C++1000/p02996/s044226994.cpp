#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector<pair<ll, ll>> p;
	rep(i, 0, n) {
		ll a, b; cin >> a >> b;
		p.emplace_back(b, a);
	}
	sort(p.begin(), p.end());

	ll now = 0;
	rep(i, 0, n) {
		now += p[i].second;
		if (now > p[i].first) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}
