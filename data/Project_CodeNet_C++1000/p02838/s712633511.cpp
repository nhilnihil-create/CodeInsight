#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define int ll
typedef pair<int,int> pii;
#define fi first
#define se second
#define Sort(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/4
#define INTINF INT_MAX/2
#define all(x) (x).begin(),(x).end()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define debug_vec(v) cerr<<#v<<":";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
template<class T> inline bool chmax(T &a, T b){if(a < b){a = b;return true;}return false;}
template<class T> inline bool chmin(T &a, T b){if(a > b){a = b;return true;}return false;}
/*----------------------------------------------------------------*/
// const int MOD = 998244353;
const int MOD = 1000000007;
ll bitpow(ll x,ll n){
    ll ans = 1;
    while(n > 0){
        if(n%2 == 1) ans = ans * x % MOD;
        x = x * x %MOD;
        n = n >> 1;
    }
    return ans;
}
/*----------------------------------------------------------------*/
signed main(){

	int n;
	cin >> n;
	vll a(n);
	rep(i,n)cin >> a[i];

	int bit[61] = {};
	for(auto x:a){
		rep(i,60){
			if(x&(1LL<<i))bit[i]++;
		}
	}
	int ans = 0;
	rep(i,n){
		int res = 0;
		int pre = 0;
		rep(j,80){
			int cnt;
			if(j < 60)cnt = bit[j];
			else cnt = 0;

			if(j < 60 && (a[i]&(1LL<<j)))cnt = n-cnt;
			cnt += pre;
			pre = cnt/2;
			res += cnt%2 * bitpow(2,j);
			res %= MOD;
			// if(i == 0)cerr << bit[j] << " " <<  cnt << " " << res << endl;
		}
		// cerr << i << " : " << res << endl;
		ans = (ans+res)%MOD;
	}
	cout << ans*bitpow(2,MOD-2)%MOD << endl;



	return 0;
}
/*----------------------------------------------------------------*/

// g++ -std=gnu++17 code1.cpp
// sudo pip3 install --upgrade online-judge-tools
// rm -r -f test;oj dl https://code-festival-2017-qualb.contest.atcoder.jp/tasks/code_festival_2017_qualb_b
// rm -r -f test;oj dl https://abc147.contest.atcoder.jp/tasks/abc147_d