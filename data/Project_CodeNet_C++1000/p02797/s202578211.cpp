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

const long long int INF=1000000000;

signed main(){
	ll n,k,s; cin>>n>>k>>s;
	vl ans(n);
	if(s==INF){
		rep(i,0,k)ans[i]=INF;
		rep(i,k,n)ans[i]=1;
	}
	else{
		rep(i,0,k)ans[i]=s;
		rep(i,k,n)ans[i]=INF;
	}
	for(auto c:ans)cout<<c<<" ";
	cout<<endl;
	
	return 0;
}