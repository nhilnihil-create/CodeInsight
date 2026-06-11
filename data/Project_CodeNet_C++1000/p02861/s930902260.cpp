#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	vector<int> p(n);
	rep(i, n) p[i] = i;
	double tot = 0;
	int cnt = 0;
	do {
		rep(i, n - 1) {
			int dx = x[p[i + 1]] - x[p[i]];
			int dy = y[p[i + 1]] - y[p[i]];
			double s = sqrt(dx * dx + dy * dy);
			tot += s;
		}
		cnt++;
	} while (next_permutation(p.begin(), p.end()));
	printf("%.10f\n", tot / cnt);
	return 0;
}