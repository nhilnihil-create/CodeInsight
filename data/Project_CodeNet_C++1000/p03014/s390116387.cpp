#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;


signed main(){
	//cout << fixed << setprecision(10);
	int h,w; cin >> h >> w;
	vector<string> vec(h);
	rep(i,0,h){
		cin >> vec[i];
	}
	ll ans = 0;
	vvl g(h + 1,vl(w + 1));
	rep(i,0,h){
		ll cnt = 0;
		ll ind = 0;
		rep(j,0,w){
			if(vec[i][j] == '.'){
				cnt++;
			}
			else{
				g[i][ind] += cnt;
				g[i][j] -= cnt;
				ind = j + 1;
				cnt = 0;
			}
		}
		g[i][ind] += cnt;
		rep(j,1,w){
			g[i][j] += g[i][j - 1];
		}
	}
	vvl f(h + 1,vl(w + 1));
	rep(j,0,w){
		ll cnt = 0;
		ll ind = 0;
		rep(i,0,h){
			if(vec[i][j] == '.'){
				cnt++;
			}
			else{
				f[ind][j] += cnt;
				f[i][j] -= cnt;
				ind = i + 1;
				cnt = 0;
			}
		}
		f[ind][j] += cnt;
		rep(i,1,h){
			f[i][j] += f[i - 1][j];
		}
	}
	rep(i,0,h){
		rep(j,0,w){
			chmax(ans , g[i][j] + f[i][j]);
		}
	}
	cout << ans - 1<< endl;
}