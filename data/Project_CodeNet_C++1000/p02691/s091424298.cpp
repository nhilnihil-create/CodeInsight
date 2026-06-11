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
  ll n;
  cin>>n;
  vl a(n);
  vl L(200007,0);
  vl R(200007,0);
  rep(i,n){
      cin>>a[i];
      ll x=i+1+a[i],y=i+1-a[i];
      if(0<x&&x<200007){
          L[x]++;
      }
      if(0<y&&y<200007){
          R[y]++;
      }
  }
  ll ans=0;
  for(ll i=1;i<=n;i++){
      ans+=L[i]*R[i];
  }
  print(ans);
}
