#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
//#define ll long long
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define rep(i, n) REP(i, 0, n)
#define rep_rev(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define all(x) (x).begin(),(x).end()
ll t1,t2,t3;
const ll mod = 1000000007;
const int INF = 1e9;
const ll INFLONG = 1e18;




int main(){
  ll n,k;
  cin >> n >> k;
  vector<ll> vec(k+1,0);
  ll ans = 0;
  for(ll i = k;i>0;i--){
    ll mul = k / i;
    ll t1 = n;
    ll req = 1;
    while(t1 != 0){
      if(t1 & 1){
        req *= mul;
        req %= mod;
      }
      mul *= mul;
      mul %= mod;
      t1 = t1 >> 1;
    }
    t3 = req;
    ll ward = i * 2;
    while(ward <= k){
      t3 -= vec[ward];
      if(t3 < 0){
        t3 += mod;
      }
      ward += i;
    }
    vec[i] = t3;
    ans += t3 * i;
    ans %= mod;
    //cout << vec[i] << endl;
    //cout << ans << endl;
  }
  cout << ans << endl;
}