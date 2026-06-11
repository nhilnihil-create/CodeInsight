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
const ll mod = 998244353;
const int INF = 1e9;
const ll INFLONG = 1e18;

ll calc_n(ll k){
  ll ret = 1;
  while(ret * (ret+1) / 2 <= k){
    ret++;
  }
  return ret-1;
}

int main(){
  ll n;
  cin >> n;
  ll ans = 0;
  ull len = sqrt(n);
  REP(i,2,len+1){
    ll sum = 0;
    while(n % i == 0){
      n /= i;
      sum++;
    }
    ans += calc_n(sum);
  }
  if(n != 1){
    ans++;
  }
  cout << ans << endl;
}