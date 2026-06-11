#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2
#define all(x) (x).begin(),(x).end()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define debug_vec(v) cerr<<#v<<":";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
//----------------------------------------------------------------

// int MOD = 998244353;
int MOD = 1000000007;

//----------------------------------------------------------------
signed main(){

	ll n;
	cin >> n;
	ll m = (1LL<<n);
	vll s(m);
	rep(i,m)cin >> s[i];
	SORT(s);
	ll maxi = s[m-1];

	multiset<ll> parent,child;
	parent.insert(-1*maxi);
	rep(i,m-1)child.insert(-1*s[i]);

	rep(i,n){
		vll tmp;
		for(auto x:parent){
			auto itr = child.lower_bound(x+1);
			if(itr == child.end()){
				cout << "No" << endl;
				return 0;
			}else{
				ll y = *itr;
				tmp.pb(y);
				child.erase(itr);
			}
		}
		for(auto x:tmp)parent.insert(x);
	}
	cout << "Yes" << endl;




	return 0;
}

//----------------------------------------------------------------

// g++ -std=c++14 code1.cpp
// sudo pip3 install --upgrade online-judge-tools
// rm -r -f test;oj dl https://code-festival-2018-quala.contest.atcoder.jp/tasks/code_festival_2018_quala_c
// rm -r -f test;oj dl https://ddcc2017-final.contest.atcoder.jp/tasks/ddcc2017_final_b
// rm -r -f test;oj dl https://abc140.contest.atcoder.jp/tasks/abc140_a