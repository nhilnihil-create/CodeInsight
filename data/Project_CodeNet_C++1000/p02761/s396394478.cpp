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

	
	int n,m;
	cin >> n >> m;
	int s[10];
	int c[10];
	rep(i,m)cin >> s[i] >> c[i];

	int a,b;
	if(n == 1){
		a = 0;
		b = 10;
	}
	if(n == 2){
		a = 10;
		b = 100;
	}
	if(n == 3){
		a = 100;
		b = 1000;
	}

	for(int i = a;i < b;i++){
		int f = 1;
		rep(j,m){
			int x = 1;
			rep(k,n-s[j]+1)x *= 10;
			if(i%x/(x/10) != c[j])f = 0;
		}
		if(f){
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;



	

	return 0;
}
/*----------------------------------------------------------------*/

// g++ -std=gnu++17 code1.cpp
// sudo pip3 install --upgrade online-judge-tools
// rm -r -f test;oj dl https://code-festival-2018-quala.contest.atcoder.jp/tasks/code_festival_2018_quala_c
// rm -r -f test;oj dl https://abc157.contest.atcoder.jp/tasks/abc157_c