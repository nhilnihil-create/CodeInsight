#include "bits/stdc++.h"
using namespace std;
using ll = long long; using ull = unsigned long long;
#define int ll
using vb = vector<bool>; using vvb = vector<vb>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
using pii = pair<int,int>; using pll = pair<ll,ll>;
#define FOR(i,a,b) for(ll i = (a); i < (ll)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(ll i = (ll)(b)-1;i >= a;--i)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define eb(val) emplace_back(val)
const double PI = acos(-1);
const double EPS = 1e-10;
const ll MOD = 1e9+7;
void cioacc(){//accelerate cin/cout
  cin.tie(0);
  ios::sync_with_stdio(false);
}
signed main(){
  cout << fixed << setprecision(10);
  int n;
  cin >> n;
  vector<double> a(n),b(n);
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];
  double ans = 0;
  REP(i,n) ans += abs(a[i]-b[i]);
  cout << ans << endl;
  ans = 0;
  REP(i,n) ans += ((a[i]-b[i])*(a[i]-b[i]));
  cout << sqrt(ans) << endl;
  ans = 0;
  REP(i,n) ans += pow(abs(a[i]-b[i]),3.);
  cout << pow(ans,1./3) << endl;
  ans = 0;
  REP(i,n) ans = max(ans,abs(a[i]-b[i]));
  cout << ans << endl;
}
