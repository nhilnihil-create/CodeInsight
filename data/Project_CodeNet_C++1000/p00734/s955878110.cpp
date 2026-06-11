#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e12;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	while(1){
		cin >> n >> m;
		if(n + m == 0) break;
		vector<int> a(n), b(m);
		int sa = 0, sb = 0;
		rep(i, 0, n){
			cin >> a[i];
			sa += a[i];
		}
		rep(i, 0, m){
			cin >> b[i];
			sb += b[i];
		}
		sort(all(a));
		sort(all(b));
		int ansa = INF, ansb = 0;
		rep(i, 0, n){
			rep(j, 0, m){
				if(sa - a[i] + b[j] == sb + a[i] - b[j]){
					if(a[i] + b[j] <= ansa + ansb){
						ansa = a[i];
						ansb = b[j];
					}
				}
			}
		}
		if(ansa == INF) cout << -1 << endl;
		else cout << ansa << ' ' << ansb << endl;
	}
}
