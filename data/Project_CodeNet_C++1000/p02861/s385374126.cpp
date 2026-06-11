#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int n;
	cin >> n;
	vector<pii> v(n);
	rep(i, n) cin >> v[i].first >> v[i].second;
	vector<int> p(n);
	rep(i, n) p[i] = i;
	double sum = 0;
	int cnt = 0;
	do {
		rep(i, n - 1) {
			int s = p[i];
			int t = p[i + 1];
			int dx = v[t].first - v[s].first;
			int dy = v[t].second - v[s].second;
			sum += sqrt(dx * dx + dy * dy);
		}
		cnt++;
	} while (next_permutation(p.begin(), p.end()));
	printf("%.10f", sum / cnt);
	return 0;
}