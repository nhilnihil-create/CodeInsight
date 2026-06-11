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
#include<utility>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll INF = mod * mod;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define stop char nyaa;cin>>nyaa;

void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	vector<int> v;
	vector<vector<bool>> u(n);
	ll ans = 0;
	per(j, 60) {
		int cnt = 0;
		ll k = (ll)1 << j;
		rep(i, n) {
			if (k&a[i])cnt++;
		}
		if (cnt % 2 == 0) {
			v.push_back(j);
			rep(i, n) {
				if (k&a[i])u[i].push_back(true);
				else u[i].push_back(false);
			}
		}
		else {
			ans += k;
		}
	}
	ll s = 0;
	int le = 0;
	ll asum = 0;
	rep(j, v.size()) {
		/*cout << "!" << endl;
		rep(i, n) {
			rep(k, v.size()) {
				cout << u[i][k];
			}
			cout << endl;
		}*/
		Rep(i, le, n) {
			if (u[i][j]) {
				swap(u[i], u[le]); le++;
				rep(x, n) {
					if (x == le - 1)continue;
					if (u[x][j]) {
						rep(k, v.size()) {
							u[x][k] = u[x][k] ^ u[le - 1][k];
						}
					}
				}

				break;
			}
		}
	}
	rep(i, le) {
		rep(j, v.size()) {
			if (u[i][j]) {
				asum^=(ll)1<<v[j];
			}
		}
	}
	//cout << ans << endl;
	ans += 2 * asum;
	cout << ans << endl;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
	//stop
	return 0;
}
