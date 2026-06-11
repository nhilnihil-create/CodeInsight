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

signed main(){
	ll n,d; cin>>n>>d;
	ll ans=0;
	rep(i,1,n+1){
		for(ll j=2;j*j<=i;j++){
			if(j/10==0 && (i/j)/10==0){
				if(i%j==0 && i/j>1){
					ll k=i/j;
					ll a=k*10+j;
					ll b=j*10+k;
					if(a<=d && a!=b)ans++;
					if(b<=d && a!=b)ans++;
					if(a<=d && a==b)ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	
	
	
	return 0;
}