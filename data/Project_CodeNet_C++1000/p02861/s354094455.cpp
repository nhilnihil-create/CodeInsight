#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N;
	cin >> N;
	vector<pint> xy(N);
	vector<int> p(N);
	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		xy[i] = make_pair(x, y);
		p[i] = i;
	}

	int cnt = 0;
	double sum = 0.0;
	do {
		for (int i = 0; i < N-1; ++i) {
			int x = (xy[p[i]].first - xy[p[i + 1]].first);
			x = x * x;
			int y = (xy[p[i]].second - xy[p[i + 1]].second);
			y = y * y;

			sum += sqrt(x + y);
		}
		cnt++;
	} while (next_permutation(p.begin(), p.end()));

	double ans = sum / cnt;
	cout << fixed << setprecision(14) << ans << endl;

	return 0;
}
