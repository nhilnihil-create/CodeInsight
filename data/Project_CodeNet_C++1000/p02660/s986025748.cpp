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
const ll MAX = 510000LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};
//素因数分解O(√n)
map<ll,ll>prime_factor(ll n){
  map<ll,ll>res;
  for(ll i=2;i*i<=n;i++){
    while(n%i==0){
      res[i]++;
      n/=i;
    }
  }
  if(n!=1)res[n]=1;
  return res;
}
int main(){
  ll n;cin>>n;
  map<ll,ll>M=prime_factor(n);
  ll ans=0;
  for(auto p:M){
    ll d=p.second;
    ll i=1;
    while(d>=i){
      ans++;
      
      d-=i;
      i++;
    }
  }
  cout<<ans<<endl;
}
