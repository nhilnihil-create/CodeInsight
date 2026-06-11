// F - Engines
#include <bits/stdc++.h>

using namespace std;

struct point {
	int x, y;
	double v;
	bool operator<(const point &p) const { return v < p.v; }
};

int main(int argc, char *argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<point> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		p[i].v = atan2(p[i].y, p[i].x);
	}
	sort(p.begin(), p.end());
	vector<pair<long long, long long> > a(1);
	for (int i = 0; i < 2 * n; i++) {
		long long x = p[i % n].x, y = p[i % n].y;
		a.push_back(make_pair(a[i].first + x, a[i].second + y));
	}

	long long ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i; j < i + n; j++) {
			long long x = a[j + 1].first - a[i].first, y = a[j + 1].second - a[i].second;
			ans = max(ans, x * x + y * y);
		}

	cout << setprecision(20) << sqrt(ans) << endl;

	return 0;
}
