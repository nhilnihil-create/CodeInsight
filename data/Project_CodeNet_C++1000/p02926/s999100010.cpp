#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

bool cmp1(PII p1, PII p2) {
	if (p1.first < p2.first) return true;
	if (p1.first > p2.first) return false;
	return p1.second < p2.second;
}

bool cmp2(PII p1, PII p2) {
	if (p1.first > p2.first) return true;
	if (p1.first < p2.first) return false;
	return p1.second > p2.second;
}

ll mul(PII p1, PII p2, PII o) {
	return 1LL * (p1.first - o.first) * (p2.second - o.second) - 1LL * (p2.first - o.first) * (p1.second - o.second);
}

vector<PII> getHalf(vector<PII> &p) {
	vector<PII> res;
	res.push_back(p.front());
	for (int i = 1; i < p.size(); i++) {
		while (res.size() > 1 && mul(res[res.size() - 1], p[i], res[res.size() - 2]) <= 0) res.pop_back();
		res.push_back(p[i]);
	}
	return res;
}

vector<PII> getConvex(vector<PII> &p) {
	sort(p.begin(), p.end(), cmp1);
	vector<PII> res = getHalf(p);
	res.pop_back();
	sort(p.begin(), p.end(), cmp2);
	vector<PII> h = getHalf(p);
	h.pop_back();
	for (int i = 0; i < h.size(); i++) {
		res.push_back(h[i]);
	}
	return res;
}

int main() {
	vector<PII> p;
	p.push_back(make_pair(0, 0));
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		vector<PII> np;
		for (auto e: p) {
			np.push_back(e);
			np.push_back(make_pair(e.first + x, e.second + y));
		}
		p = getConvex(np);
		// for (auto e: p) {
		// 	cout << e.first << " " << e.second << endl;
		// }
		// cout << endl;
	}
	ll ans = 0;
	for (auto e: p) {
		ans = max(1LL * e.first * e.first + 1LL * e.second * e.second, ans);
	}
	cout << setprecision(15) << sqrt(ans) << endl;
	return 0;
}