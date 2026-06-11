#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;
#define rep(i,a,b) for(ll i=a ; i<b ; i++)
#define qrep(que, ite) for(auto ite=begin(que) ; ite!=end(que) ; ite++)
const int max_n = 1e5;
const ll mod = 1e9+7;
const ll INF = 1LL<<60;
const int inf = 1e5;
//typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
ll mo = 998244353;
ll gcd(ll a, ll b) { return a ? gcd(b%a, a) : b; }
int main(){
  ll n,k; cin >> n >> k;
  vector<ll> v(n);
  rep(i,0,n){
    cin >> v[i];
  }
  ll ans = 0;
  rep(i,0,n){
    ll m=0, al=0;
    rep(j,i,n-1){
      if(v[i]>v[j+1]) m++;
    }
    rep(j,0,n){
      if(v[i]>v[j]) al++;
    }
    ans += k*m % mod;
    ans %= mod;
    ans += ((k-1) * k)/2 % mod * al % mod;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
