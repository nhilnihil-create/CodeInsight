#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

int N;
vector<pi> P;

void input_init(void) {
	cin >> N;
	P.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> P[i].first >> P[i].second;
	sort(P.begin(), P.end());
	P.erase(unique(P.begin(), P.end()), P.end());
	N = P.size();
}

ll det(pi a, pi b) {
	ll x = (ll)a.first * b.second;
	ll y = (ll)-a.second * b.first;
	return x + y;
}

vector<pi> convex_hull(vector<pi> &ps, int n) {
	int k = 0;
	vector<pi> qs(n * 2);
	for (int i = 0; i < n; ++i) {
		while (k > 1) {
			pi a = make_pair(qs[k - 1].first - qs[k - 2].first, qs[k - 1].second - qs[k - 2].second);
			pi b = make_pair(ps[i].first - qs[k - 1].first, ps[i].second - qs[k - 1].second);
			if (det(a, b) <= (ll)0)
				k--;
			else
				break;
		}
		qs[k++] = ps[i];
	}
	for (int i = n - 2, t = k; i >= 0; --i) {
		while (k > t) {
			pi a = make_pair(qs[k - 1].first - qs[k - 2].first, qs[k - 1].second - qs[k - 2].second);
			pi b = make_pair(ps[i].first - qs[k - 1].first, ps[i].second - qs[k - 1].second);
			if (det(a, b) <= (ll)0)
				k--;
			else
				break;
		}
		qs[k++] = ps[i];
	}
	qs.resize(k - 1);
	return qs;
}

ll calcu_dist(pi a, pi b) {
	ll x = (ll)abs(a.first - b.first);
	ll y = (ll)abs(a.second - b.second);
	return x + y;
}

int main(void) {
	input_init();
	vector<pi> qs = convex_hull(P, N);
	ll ans = (ll)0;
	for (int i = 0; i < (int)qs.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			ll d = calcu_dist(qs[i], qs[j]);
			ans = max(d, ans);
		}
	}
	cout << ans << '\n';
	return 0;
}
