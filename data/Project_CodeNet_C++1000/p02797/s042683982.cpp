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
const ll INF=1000000000;

signed main(){
	ll n,s,k; cin>>n>>k>>s;
	vl ans(n);
	bool t=true;
	if(n==k){
		rep(i,0,n)ans[i]=s;
	}
	else if(s==1){
		ll cnt=0;
		rep(i,0,n){
			if(i<k)ans[i]=1;
			else ans[i]=INF;
		}
	}
	else if(s==INF){
		ll cnt=0;
		rep(i,0,n){
			if(i<=k){
				if(t)ans[i]=1;
				else ans[i]=INF-(ll)1;
				t=!t;
			}
			else ans[i]=2;
		}
	}
	else{
		rep(i,0,n){
			if(i<=k){
				if(t)ans[i]=1;
				else ans[i]=s-1;
				t=!t;
			}
			else ans[i]=INF;
		}
	}
	rep(i,0,n){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}