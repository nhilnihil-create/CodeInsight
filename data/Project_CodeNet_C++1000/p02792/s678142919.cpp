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


/*----------------------------------------------------------------*/
signed main(){


	int n;
	cin >> n;

	map<pair<int,int>,int> ca,cb;
	for(int i = 1;i <= n;i++){
		string s = to_string(i);
		ca[make_pair(s[0],s[s.size()-1])]++;
		cb[make_pair(s[s.size()-1],s[0])]++;
	}
	int ans = 0;
	for(auto x:ca){
		ans += x.se*cb[x.fi];
	}
	cout << ans << endl;

	
	
	return 0;
}
/*----------------------------------------------------------------*/

// g++ -std=gnu++17 code1.cpp
// sudo pip3 install --upgrade online-judge-tools
// rm -r -f test;oj dl https://code-festival-2017-qualb.contest.atcoder.jp/tasks/code_festival_2017_qualb_b
// rm -r -f test;oj dl https://abc152.contest.atcoder.jp/tasks/abc152_d