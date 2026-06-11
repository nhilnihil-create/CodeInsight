#include <bits/stdc++.h>

using namespace std;

int main() {
	int x, y, a, b, c;
	scanf("%d %d %d %d %d", &x, &y, &a, &b, &c);
	vector<int> p(a);
	for(int &val : p) scanf("%d", &val);
	vector<int> q(b);
	for(int &val : q) scanf("%d", &val);
	vector<int> r(c);
	for(int &val : r) scanf("%d", &val);

	sort(p.rbegin(), p.rend());
	sort(q.rbegin(), q.rend());
	p.resize(x);
	q.resize(y);
	r.insert(r.end(), p.begin(), p.end());
	r.insert(r.end(), q.begin(), q.end());
	sort(r.rbegin(), r.rend());

	long long ans = 0;
	for(int i = 0; i < x + y; i++) {
		ans += r[i];
	}

	printf("%lld\n", ans);
}
