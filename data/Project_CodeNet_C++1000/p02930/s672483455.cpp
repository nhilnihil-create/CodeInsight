#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 998244353

typedef long long ll;
typedef pair<ll,ll> P;
ll ans[555][555];
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	ll n;cin >> n;
	REP(i, n){
		REP(j, n){
			if(i == j)continue;
			for(int k = 30;k >= 0;k--){
				if((i & (1 << k)) != (j & (1 << k))){
					ans[i][j] = (k + 1);
					break;
				}
			}
		}
	}
	REP(i, n-1){
		REP(j, n){
			if(i < j)cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
