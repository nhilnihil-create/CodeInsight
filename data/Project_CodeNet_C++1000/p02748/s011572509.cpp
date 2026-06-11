#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
int main() {
	int a,b,m;
	cin >> a >> b >> m;
	vector<int> heat(a), cool(b);
	rep(i,a) cin >> heat[i];
	rep(i,b) cin >> cool[i];
	int minHeat = *min_element(heat.begin(), heat.end());
	int minCool = *min_element(cool.begin(), cool.end());
	int ans = minHeat + minCool;
	rep(i, m) {
		int x, y, c;
		cin >> x >> y >> c;
		ans = min(ans, heat[x-1]+cool[y-1]-c);
	}
	cout << ans << endl;
	return 0;
}