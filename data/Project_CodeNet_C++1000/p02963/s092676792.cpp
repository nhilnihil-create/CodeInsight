#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,a,b) for(int i=a ; i<b ; i++)
#define qrep(que, ite) for(auto ite=begin(que) ; ite!=end(que) ; ite++)
const int max_n = 1e5;
const ll mod = 1e9+7;
const ll INF = 1LL<<60;
const int inf = 1<<30;
//typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
ll mo = 998244353;
ll jou(ll n, ll x){
  ll res = 1;
  while(n){
    if(n & 1) res = res*x % mo;
    x = x*x % mo;
    n >>= 1;
  }
  return res;
}
int main(){
  ll s; cin >> s;
  ll k = 1e9;
  ll a = 1;
  ll b = 1e9;
  ll c = (s+b-1)/b;
  ll d = c*b-s;
  printf("0 0 1 %lld %lld %lld\n", b,c,d);
  return 0;
}
