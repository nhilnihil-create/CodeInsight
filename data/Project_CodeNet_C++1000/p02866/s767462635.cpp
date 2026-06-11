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
typedef long double ld;
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
  int n;  cin >> n;
  vector<int> v(n), a(n,0);
  int ma = 0;
  rep(i,0,n){
    cin >> v[i];
    a[v[i]]++;
    ma = max(ma, v[i]);
  }
  ll ans = 1;
  rep(i,0,ma){
    if(!a[i] || !a[i+1]||a[0]!=1||v[0]!=0){
      cout << 0 << endl;
      return 0;
    }
    ans *= jou(a[i+1], a[i]);
    ans %= mo;
  }
  cout << ans << endl;
  return 0;
}
