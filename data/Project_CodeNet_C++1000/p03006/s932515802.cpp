#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

typedef pair<ll, ll> pll;

int main() {
	int n;
	cin >> n;
	vector<ll> x(n), y(n);
	rep(i,n) cin >> x[i] >> y[i];

	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	
	map<pll, int> mp;
	rep(i,n) mp[make_pair(x[i], y[i])]++;
	int ans = INF;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ll vx = x[i] - x[j];
			ll vy = y[i] - y[j];
			int t = 0;
			for (int k = 0; k < n; k++) {
				ll nx = x[k] + vx;
				ll ny = y[k] + vy;
				if (!mp[pll(nx, ny)]) t++;
			}
			ans = min(ans, t);
		}
	}
	cout << ans << endl;
}