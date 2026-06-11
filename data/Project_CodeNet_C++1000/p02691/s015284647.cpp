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
int n;


/*----------------------------------------------------------------*/
signed main(){
	
	cin >> n;
	vll a(n);
	map<int,int> mp1,mp2;
	rep(i,n){
		cin >> a[i];
		mp1[i+1-a[i]]++;
		mp2[i+1+a[i]]++;
	}

	int ans = 0;
	rep(i,n){
		int a1 = i+1-a[i];
		if(mp2.find(a1) != mp2.end()){
			ans += mp2[a1];
		}
		int a2 = i+1+a[i];
		if(mp1.find(a2) != mp1.end()){
			ans += mp1[a2];
		}
	}

	cout << ans/2 << endl;





	
	

	return 0;
}
/*----------------------------------------------------------------*/

// g++ -std=gnu++17 code1.cpp
// sudo pip3 install --upgrade online-judge-tools
// rm -r -f test;oj dl https://code-festival-2017-qualb.contest.atcoder.jp/tasks/code_festival_2017_qualb_b
// rm -r -f test;oj dl https://abc166.contest.atcoder.jp/tasks/abc166_e