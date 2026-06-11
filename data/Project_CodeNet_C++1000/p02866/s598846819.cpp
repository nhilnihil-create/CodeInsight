#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const ll MOD2=998244353;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

ll modpow(ll a,ll b){
  if(b==0){
    return 1;
  }
  else if(b%2==0){
    ll t=modpow(a,b/2);
    return t*t%MOD2;
  }
  else{
    return a*modpow(a,b-1)%MOD2;
  }
}

int main() {
  ll n;
  cin >> n;
  vl a(n),cnt(n);
  bool b=true;
  rep(i,n){
    cin >> a[i];
    if(a[0]!=0){
      b=false;
    }
    else if(i!=0&&a[i]==0){
      b=false;
    }
    else{
      cnt[a[i]]++;
    }
  }
  rep(i,n-1){
    if(cnt[i]==0&&cnt[i+1]!=0){
      b=false;
    }
  }
  if(!b){
    cout << 0 << endl;
  }
  else{
    ll ans=1;
    ll i=0;
    while(cnt[i]!=0){
      ans=ans*(modpow(cnt[i],cnt[i+1]))%MOD2;
      i++;
    }
    cout << ans << endl;
  }
}