#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y, a, b, c; scanf("%d %d %d %d %d", &x, &y, &a, &b, &c);
	multiset<pair<int, int>> s;
	vector<int> r, g, cl;
	for (int i = 0; i < a; i++) {
		int d; scanf("%d", &d);
		r.push_back(d);
	}
	for (int i = 0; i < b; i++) {
		int d; scanf("%d", &d);
		g.push_back(d);
	}
	for (int i = 0; i < c; i++) {
		int d; scanf("%d", &d);
		cl.push_back(d);
	}
	sort(r.begin(), r.end());
	sort(g.begin(), g.end());
	sort(cl.begin(), cl.end());
	while (x--) {
		s.insert({r.back(), 0});
		r.pop_back();
	}
	while (y--) {
		s.insert({g.back(), 1});
		g.pop_back();
	}
	while (c--) {
		auto v = *s.begin();
		if (cl.back() > v.first) {
			s.erase(s.begin());
			s.insert({cl.back(), 2});
			cl.pop_back();
		} else break;
	}
	long long sum = 0;
	for (auto v: s) {
		sum += v.first;
	}
	printf("%lld\n", sum);
}