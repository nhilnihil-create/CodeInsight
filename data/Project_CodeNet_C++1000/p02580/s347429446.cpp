#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define FF first
#define SS second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define all(v) (v).begin(),(v).end()
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define inf 1e18
#define mod 1000000007
#define PI 3.1415926535
#define endl "\n"
#define runtime cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

inline int sbt(int x) {return __builtin_popcount(x);}
inline int mul(int a, int b, int m = mod) { return (a * b) % m; }
inline int add(int a, int b, int m = mod) { return (a + b) % m; }
inline int sub(int a, int b, int m = mod) { return (a - b + m) % m; }



int32_t main() {
	fastio
	int n, m, k;
	cin >> n >> m >> k;
	vector<int>row(n, 0), col(m, 0);
	map<pii, int>gg;
	while (k--) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		row[x]++;
		col[y]++;
		gg.insert({{x, y}, 1});

	}
	int mxr = 0, mxc = 0;
	rep(i, 0, n) {
		mxr = max(mxr, row[i]);
	}
	rep(i, 0, m) {
		mxc = max(mxc, col[i]);
	}
	vector<int>ansr, ansc;
	rep(i, 0, n) {
		if (row[i] == mxr) {
			ansr.pb(i);
		}
	}
	rep(i, 0, m) {
		if (col[i] == mxc) {
			ansc.pb(i);
		}
	}
	int flag = 1;
	int ans = 0;
	rep(i, 0, sz(ansr)) {
		rep(j, 0, sz(ansc)) {
			int r = ansr[i];
			int c = ansc[j];
			flag = 0;
			int fans = row[r] + col[c];
			if (gg.count({r, c}) > 0) {
				fans--;
				flag = 1;
			}

			ans = max(ans, fans);
			if (!flag)break;

		}
		if (!flag)break;

	}
	cout << ans;



	runtime
	return 0;
}
