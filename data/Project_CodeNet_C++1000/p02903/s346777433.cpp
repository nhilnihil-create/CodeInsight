#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
using pl = pair<ll,ll>;
signed main(){
	ll n,m,a,b; cin>>n>>m>>a>>b;
	rep(i,0,n){
		rep(j,0,m){
			if(i<b && j<a)cout<<0;
			else if(i<b || j<a)cout<<1;
			else cout<<0;
		}
		cout<<endl;
	}

	return 0;
}