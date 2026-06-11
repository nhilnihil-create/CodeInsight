#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const ll INF = 2e15;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main(){
  vl div_a(0);
  ll a,b;
  cin>>a>>b;
  if(a>b){
      swap(a,b);
  }
  for(ll i=1;i*i<=a;i++){
    if(a%i==0){
        div_a.pb(i);
        if(i!=a/i){
            div_a.pb(a/i);
        }
    }
  }
  vl co(0);
  for(ll i=1;i*i<=b;i++){
      if(b%i==0){
          rep(j,sz(div_a)){
              if(div_a[j]==i){
                  co.pb(i);
              }
          }
          if(i!=b/i){
            rep(j,sz(div_a)){
                if(div_a[j]==b/i){
                  co.pb(b/i);
              }
            }
          }
      }
  }
  ll size=sz(co);
  ll ans=0;
  /*for (int tmp = 0; tmp < (1 << 22); tmp++) {
  bitset<22> s(tmp);
  bool OK=true;
  vl z(0);
  ll sum=0;
  rep(i,sz(co)){
      if(s[i]){
          z.pb(co[i]);
          sum++;
          rep(j,sz(z)-1){
              if(gcd(z[j],co[i])!=1){
                  OK=false;
                  j=INF;
                  i=INF;
              }
          }
      }
  }
  if(OK){
      chmax(ans,sum);
  }
}*/
  rep(i,sz(co)){
      bool sosuu=true;
      for(ll j=2;j*j<=co[i];j++){
          if(co[i]%j==0){
              sosuu=false;
          }
      }
      if(sosuu){
          ans++;
      }
  }
  print(ans);
}

