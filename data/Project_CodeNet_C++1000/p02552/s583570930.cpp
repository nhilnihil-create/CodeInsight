#include<bits/stdc++.h>
#define ll long long
#define all(v) v.begin(),v.end()
#define rall(v) v.begin(),v.end()
#define sz(x) (int)sz.size()
#define PB push_back
#define PI 3.1415926535897932384626433832795
#define what(x) cout<<#x<<" is "<<x<<endl;
using namespace std;

#ifdef LOCAL//ONLINE_JUDGE
#include "D:\c_c++\template.h"
#else
#define debug(...) 42
#endif

ll powmod(ll a,ll b,ll mod) {
    ll res=1;a%=mod;
    //assert(b>=0);
    for(;b;b>>=1){
        
      if(b&1)res=res*a%mod;
			a=a*a%mod;
    }
    return res;
}

void solve(){
	ll x;
	cin>>x;
	debug("hahah");
	cout<<(!x)<<'\n';
	debug("bhai bhai");
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
//    #ifdef LOCAL
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    #endif
    int tc=1;
    // cin>>tc;
    while(tc--)solve();
}
