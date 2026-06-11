#include <stdio.h>
#include <deque>
#include <utility>

using namespace std;
using ll = long long;

ll max(ll x, ll y) {
	if (x < y) {
		return y;
	} else {
		return x;
	}
}

int main(void) {
	ll ans = 0;
	deque<pair<char, int>> v = {make_pair(getchar(), 1)};
	int d;
	while ((d = getchar()) != EOF) {
		if (d != '<' && d != '>') {
			continue;
		}
		if (d != v.back().first) {
			v.push_back(make_pair(d, 0));
		}
		v.back().second++;
	}
	if (v.front().first == '>') {
		ans += (ll) (v.front().second + 1) * v.front().second / 2;
		v.pop_front();
	}
	if (v.back().first == '<') {
		ans += (ll) (v.back().second + 1) * v.back().second / 2;
		v.pop_back();
	}
	while (!v.empty()) {
		ll open, close;
		open = v.front().second;
		v.pop_front();
		close = v.front().second;
		v.pop_front();
		ans += (open - 1) * open / 2
					 + (close - 1) * close / 2
					 + max(open, close);
	}
	printf("%lld\n", ans);
	return 0;
}
