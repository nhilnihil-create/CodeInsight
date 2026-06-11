#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
//const ll mod = 1000000007;
//const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;
const ld pi = acos(-1.0);

typedef pair<ld, LDP> speP;

ld dist(ld x, ld y) {
	return sqrt(x*x + y * y);
}
void solve() {
	int n; cin >> n;
	vector<speP> v;
	rep(i, n) {
		ld x, y; cin >> x >> y;
		v.push_back({ atan2(y,x),{x,y} });
	}
	sort(v.begin(), v.end());
	rep(i, n) {
		speP p = v[i];
		p.first += 2 * pi;
		v.push_back(p);
	}
	ld sx = 0, sy = 0;
	int ri = 0;
	while (v[ri].first < 0) {
		sx += v[ri].second.first;
		sy += v[ri].second.second;
		ri++;
	}
	ld ans = dist(sx, sy);
	int le = 0;
	ld cur = 0;
	while (ri < v.size()) {
		ld dri = v[ri].first - cur;
		ld dle = v[le].first - (cur - pi);
		if (dle < dri) {
			cur += dle;
			sx -= v[le].second.first;
			sy -= v[le].second.second;
			le++;
		}
		else {
			cur += dri;
			sx += v[ri].second.first;
			sy += v[ri].second.second;
			ri++;
		}
		ans = max(ans, dist(sx, sy));
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(50);
	//init();
	solve();

	//cout << "finish" << endl;
	//stop
	return 0;
}
