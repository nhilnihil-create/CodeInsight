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

signed main(){
	ll n; cin>>n;
	ll ans=0;
	if(n%2==1){
		cout<<0<<endl;
		return 0;
	}
	while(n>0){
		n/=5;
		ans+=n-(n%2);
	}
	cout<<ans/2<<endl;
	
	
	return 0;
}