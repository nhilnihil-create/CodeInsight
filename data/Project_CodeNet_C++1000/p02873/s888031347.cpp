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
	ll ans = 0LL;
	deque<pair<char, ll>> v = {make_pair(getchar(), 1LL)};
	int d;
	while ((d = getchar()) != EOF) {
		if (d == '\n') {
			continue;
		}
		if (d != v.back().first) {
			v.push_back(make_pair(d, 0LL));
		}
		v.back().second++;
	}
	if (v.front().first == '>') {
		ans += (v.front().second + 1LL) * v.front().second / 2LL;
		v.pop_front();
	}
	if (v.back().first == '<') {
		ans += (v.back().second + 1LL) * v.back().second / 2LL;
		v.pop_back();
	}
	while (!v.empty()) {
		ll open, close;
		open = v.front().second;
		v.pop_front();
		close = v.front().second;
		v.pop_front();
		ans += (open - 1LL) * open / 2LL
					 + (close - 1LL) * close / 2LL
					 + max(open, close);
	}
	printf("%lld\n", ans);
	return 0;
}
