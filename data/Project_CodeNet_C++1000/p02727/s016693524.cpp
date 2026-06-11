#include <bits/stdc++.h>
#define rep(i,n) for(long long i = 0; i < (long long)(n); ++i)

using namespace std;
using ll = long long;

int main() {
	ll x, y, a, b, c;
	cin >> x >> y >> a >> b >> c;
	vector<int> red(a), gre(b), nun(c);
	rep(i, a) cin >> red[i];
	rep(i, b) cin >> gre[i];
	rep(i, c) cin >> nun[i];
	sort(red.rbegin(), red.rend());
	sort(gre.rbegin(), gre.rend());
	sort(nun.rbegin(), nun.rend());
	int nx = x - 1;
	int ny = y - 1;
	rep(i, c) {
		if (nx >= 0 && ny >= 0) {
			if (red[nx] < gre[ny] && red[nx] < nun[i]) {
				red[nx] = nun[i];
				nx--;
			}
			else if (gre[ny] < nun[i]) {
				gre[ny] = nun[i];
				ny--;
			}
		}
		else if (nx >= 0 && red[nx] < nun[i]) {
			red[nx] = nun[i];
			nx--;
		}
		else if (ny >= 0 && gre[ny] < nun[i]) {
			gre[ny] = nun[i];
			ny--;
		}
	}
	ll ans = 0;
	rep(i, x) ans += red[i];
	rep(i, y) ans += gre[i];
	cout << ans << endl;
	return 0;
}
