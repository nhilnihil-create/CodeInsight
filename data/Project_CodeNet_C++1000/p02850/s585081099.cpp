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
vector<pair<int,int>> G[100100];
int ans[100010] = {};
int used[100100] = {};
void dfs(int n,int c){
	used[n] = 1;
	int nc = 1;
	for(auto p:G[n]){
		if(!used[p.fi]){
			if(c == nc)nc++;
			ans[p.se] = nc;
			dfs(p.fi,nc);
			nc++;
		}
	}
	return;
}
/*----------------------------------------------------------------*/
signed main(){

	int n;
	cin >> n;

	rep(i,n-1){
		int a,b;
		cin >> a >> b;
		a--;b--;
		G[a].pb(MP(b,i));
		G[b].pb(MP(a,i));
	}

	int maxi = 0;
	int id = -1;
	rep(i,n){
		if(chmax(maxi,int(G[i].size()))){
			id = i;
		}
	}
	cout << maxi << endl;

	dfs(id,-1);
	rep(i,n-1)cout << ans[i] << endl;

	





	return 0;
}
/*----------------------------------------------------------------*/

// g++ -std=gnu++17 code1.cpp
// sudo pip3 install --upgrade online-judge-tools
// rm -r -f test;oj dl https://code-festival-2017-qualb.contest.atcoder.jp/tasks/code_festival_2017_qualb_b
// rm -r -f test;oj dl https://abc146.contest.atcoder.jp/tasks/abc146_d