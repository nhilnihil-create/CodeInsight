//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const int INF= 1e9+5;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
ll modpow(ll a, ll n, ll mod) {
  
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main(){
  string s;cin>>s;
  ll n=s.size();
  ll ans=0;
  ll count=0;
  rep(i,n){
    if(s[i]=='1'){
      count++;
      ans+=modpow(2,count-1,MOD)*modpow(3,n-i-1,MOD)%MOD;
      ans%=MOD;
    }
  }
  ans+=modpow(2,count,MOD);
  ans%=MOD;
  cout<<ans<<endl;
}
      
    
          
    
    
          