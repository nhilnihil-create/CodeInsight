#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b) for (int i = a; i < (b); ++i)
#define all(x) (x).begin(),(x).end()
#define YY cout << "Yes" << endl;
#define NN cout << "No" << endl;
#define v vector
const int INF = 1000000007;
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
// *max_element(all(d));
int solve(){ 
  int n;
  cin >> n;
  v<int>d(n),cnt(n);
  rep(i,n)cin >> d[i];
  rep(i,n)++cnt[d[i]];
  int MAX = *max_element(all(d));
  bool can = true;
  if(d[0] != 0 || cnt[0] != 1)can = false;
  ll ans = 1;
  REP(i,1,MAX+1){
    if(cnt[i] == 0)can = false;
    rep(j,cnt[i]){
      ans = ans * cnt[i - 1] % 998244353;
    }
  }
  if(!can)ans = 0;
  cout << ans << endl;
  return 0; 
}
int main(){
  // ios::sync_with_stdio(false);cin.tie(nullptr);
  // cout << fixed;cout << setprecision(16) << endl; 
  solve();
  return 0;
} 