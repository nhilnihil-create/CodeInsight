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

	
	string s;
	cin >> s;
	int n = s.size() + 1;

	int L = 0;
	int R = 0;
	char now = '<';
	int ans = 0;
	for(auto c:s){
		// cerr << L << ", " << R << endl;
		if(now == c){
			if(c == '<')L++;
			if(c == '>')R++;
		}
		else if(now == '<' && c == '>'){
			now = '>';
			R++;
		}
		else if(now == '>' && c == '<'){
			now = '<';
			int mini = min(L,R);
			int maxi = max(L,R);
			// cerr << L << ", " << R << endl;
 			ans += mini*(mini-1)/2 + maxi*(maxi+1)/2;
			L = 1;
			R = 0;
		}
	}
	// cerr << L << ", " << R << endl;
	int mini = min(L,R);
	int maxi = max(L,R);
	ans += mini*(mini-1)/2 + maxi*(maxi+1)/2;
	cout << ans << endl;

	return 0;
}
/*----------------------------------------------------------------*/

// g++ -std=gnu++17 code1.cpp
// sudo pip3 install --upgrade online-judge-tools
// rm -r -f test;oj dl https://code-festival-2018-quala.contest.atcoder.jp/tasks/code_festival_2018_quala_c
// rm -r -f test;oj dl https://agc040.contest.atcoder.jp/tasks/agc040_a