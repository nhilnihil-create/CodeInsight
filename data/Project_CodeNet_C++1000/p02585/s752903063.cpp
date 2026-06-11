#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define rep(i, a, n) for (int i=(a); i<(n); i++)
#define per(i, a, n) for (int i=(a); i>(n); i--)
typedef long long ll;
const int maxn = 2e5+5;
const int mod = 1e9+7;
using namespace std;

ll p[maxn], c[maxn], sum[maxn];
vector<ll> v;

void solve() {
	ll n,k,ans=-1e18; cin >> n >> k;
	rep(i,1,n+1) cin >> p[i];
	rep(i,1,n+1) cin >> c[i];
	rep(i,1,n+1) {
		ll t = p[i], cnt=1, res=c[i];
		v.clear();
		v.push_back(0); v.push_back(c[i]);
		ans = max(ans, c[i]);
		while(t != i && cnt < k) {
			res += c[t];
			ans = max(res, ans);
			v.push_back(c[t]);
			t = p[t];
			cnt++;
		}
		ll mxi = 1;
		rep(j,1,cnt+1) {
			sum[j] = sum[j-1] + v[j];
			if (sum[j] > sum[mxi]) {
				mxi = j;
			}
		}
		//rep(i,1,cnt+1) cout << v[i] << " \n"[i==cnt];
		//cout << ans << '\n';
		ll tmp = res;
		if (k - cnt > 0) {
			// cout << cnt << '\n';
			// cout << k-cnt << ' ' << (k-cnt)%cnt << '\n';
			if (sum[cnt] > 0) {
				res += sum[cnt]*((k-cnt)/cnt);
				ans = max(ans, res);
				rep(j,1,(k-cnt)%cnt+1) {
					res += v[j];
					//cout << i << "----" << j << ' ' <<  v[j] << ' ';
					ans = max(ans, res);
					//cout << ans << '\n';
				}
				if ((k-cnt)%cnt==0) {
					res = tmp + sum[cnt]*((k-cnt)/cnt-1);
					ans = max(ans, res);
					rep(j,1,cnt+1) {
						res += v[j];
						ans = max(ans, res);
					}
				}
			}
			res = tmp;
			rep(j,1,min(cnt,k-cnt)+1) {
				res += v[j];
				ans = max(ans, res);
			}
			//cout << res << '\n';
			
			//res -= sum[cnt]*((k-cnt)/cnt);
			
			// rep(i,1,k-cnt+1) {
			// 	res += v[i%cnt+1];
			// 	ans = max(ans, res);
			// }
		}
	}
	cout << ans << '\n';
}

int main(int argc, char * argv[]) 
{
	//ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef DEBUG
	freopen("C:/Users/Fish_Brother/Desktop/in", "r", stdin);
	//freopen("C:/Users/Fish_Brother/Desktop/out", "w", stdout);
#endif

	//int t; cin >> t; while(t--)
	solve();

    return 0;
}