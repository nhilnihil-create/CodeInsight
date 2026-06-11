#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>
#define PI 3.141592653589793
const int INF = 1001001001;

int main() {
	int a, b, m;
	cin >> a >> b >> m;
	vector<int> r(a), d(b);
	rep(i, a) cin >> r[i];
	rep(i, b) cin >> d[i];
	int ans = INF;
	rep(i, m) {
		int x, y, c;
		cin >> x >> y >> c;
		ans = min(ans, r[x-1] + d[y-1] - c);
	}
	sort(r.begin(), r.end());
	sort(d.begin(), d.end());
	ans = min(ans, r[0] + d[0]);
	cout << ans << endl;
}