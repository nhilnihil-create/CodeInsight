#include <bits/stdc++.h>
#define INF pow(10, 9) + 7
#define rep(i, N) for(ll i = 0; i < N; i++)
#define rep2(i, j, k) for(ll i = j; i < k; i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define chmax(x, y) x = max(x, y)
#define print(x) cout << x << "\n"
#define ALL(v) v.begin(), v.end()
#define SUM(v) accumulate(ALL(v), 0)
#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define SORT(v) sort(ALL(v))
#define REV(v) reverse(ALL(v))
typedef long long ll;
using namespace std;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vs = vector<string>;
using vvs = vector<vector<string>>;

void solve(){
	
	ll H, W, cnt;
	cin >> H >> W;
	vs s(H);
	rep(i, H)  cin >> s[i];
	
	vvl res(H, vl(W));
	
	rep(i, H){
		cnt = 0;
		rep(j, W){
			if(s[i][j] == '#') cnt = 0;
			else{
				cnt += 1;
				res[i][j] += cnt;
			}
		}
	}
	
	rep(i, W){
		cnt = 0;
		rep(j, H){
			if(s[j][i] == '#') cnt = 0;
			else{
				cnt += 1;
				res[j][i] += cnt;
			}
		}
	}
	
	for(ll i = H - 1; i >= 0; i--){
		cnt = 0;
		for(ll j = W - 1; j >= 0; j--){
			if(s[i][j] == '#') cnt = 0;
			else{
				cnt += 1;
				res[i][j] += cnt;
			}
		}
	}
	
	for(ll i = W - 1; i >= 0; i--){
		cnt = 0;
		for(ll j = H - 1; j >= 0; j--){
			if(s[j][i] == '#') cnt = 0;
			else{
				cnt += 1;
				res[j][i] += cnt;
			}
		}
	}

	
	ll ans = 0;
	rep(i, H) rep(j, W) chmax(ans, res[i][j]);
	
	print(ans - 3);

}	

int main(){
    
    fastio;
	solve();
    
	return 0;
	
}
