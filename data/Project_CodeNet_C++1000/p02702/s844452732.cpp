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
// const int MOD = 1000000007;

/*----------------------------------------------------------------*/
signed main(){
	

	string s;
	cin >> s;
	int n = s.size();
	vll t(n+1,0);
	
	int x = 1;
	rep(i,n){
		t[i+1] = (t[i] + int(s[n-1-i]-'0')*x)%2019;
		x = (x*10)%2019;
	}
	
	int cnt[2031] = {};
	rep(i,n+1)cnt[t[i]]++;

	int ans = 0;
	rep(i,2024)ans += cnt[i]*(cnt[i]-1)/2;

	cout << ans << endl;

	rep(i,n+1)cerr << t[n-i] << " ";
	cerr << endl;



	return 0;
}
/*----------------------------------------------------------------*/

// g++ -std=gnu++17 code1.cpp
// sudo pip3 install --upgrade online-judge-tools
// rm -r -f test;oj dl https://abc174.contest.atcoder.jp/tasks/abc174_b
// rm -r -f test;oj d https://atcoder.jp/contests/abc164/tasks/abc164_d