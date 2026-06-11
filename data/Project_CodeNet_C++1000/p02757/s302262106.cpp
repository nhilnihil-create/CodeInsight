#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
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

int main() {
  ll n,p;
  cin >> n >> p;
  string s;
  cin >> s;
  ll ans=0;
  if(10%p==0){
    rep(i,n){
      if((s[i]-'0')%p==0){
        ans +=i+1;
      }
    }
  }
  else{
    ll x=1;
    vl a(n);
    vl k(n+1,0);
    rep(i,n){
      a[i]=((s[n-i-1]-'0')*x)%p;
      x *=10;
      x %=p;
    }
    k[0]=a[0]%p;
    FOR(i,1,n){
      k[i]=(k[i-1]+a[i])%p;
    }
    sort(k.begin(),k.end());
    ll cnt=0;
    rep(i,n){
      if(k[i]==k[i+1]){
        cnt++;
      }
      else{
        ans +=cnt*(cnt+1)/2;
        cnt=0;
      }
    }
    ans +=cnt*(cnt+1)/2;
  }
  cout << ans << endl;
}