//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define bit(n,k) (((ll)n>>(ll)k)&1) /*nのk bit目*/
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
//const ll MOD=998244353LL;
//const ll MAX_V=114514LL;
//const ll MAX = 510000LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};
//約数の列挙O(√n)
vector<ll>divisor(ll n){
  vector<ll>res;
  for(ll i=1;i*i<=n;i++){
    if(n%i==0){
      res.push_back(i);
      if(i != n/i) res.push_back(n/i);
    }
  }
  return res;
}
ll factorial(ll x){
  if(x==0)return 1;
  return x*factorial(x-1)%MOD;
}

ll modpow(ll a, ll n, ll mod) {
  
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll comb(ll n, ll r){
  ll res=1;
    for(ll i=0;i<r;i++){
      res*=n-i;
      res%=MOD;
    }
  res*=modpow(factorial(r),MOD-2,MOD);
  res%=MOD;
  return res;
}

int main(){
  
  ll a,b,c;cin>>a>>b>>c;
  cout<<min({a+b,b+c,c+a})<<endl;
}