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
  vl z(n);
  vl w(n);
  rep(i,n){
    ll x,y;
    cin>>x>>y;
    z[i]=x+y;
    w[i]=x-y;
  }
  ll maxi_z=-INF;
  ll mini_z=INF;
  ll maxi_w=-INF;
  ll mini_w=INF;
  rep(i,n){
    chmax(maxi_z,z[i]);
    chmin(mini_z,z[i]);
    chmax(maxi_w,w[i]);
    chmin(mini_w,w[i]);
  }
  ll s=maxi_z-mini_z;
  ll t=maxi_w-mini_w;
  cout<<max(s,t)<<endl;
}
