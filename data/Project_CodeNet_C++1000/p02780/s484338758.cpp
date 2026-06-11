#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
const int MOD = 1000000007;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> p(n);
  rep(i,n) cin >> p[i];
  vector<ll> sum(n+1);
  rep(i,n) sum[i+1] = sum[i] + p[i];
  ll l = 0;
  int s = 0;
  rep(i,n+1-k) {
    ll temp = sum[i+k] - sum[i];
    if (temp > l) {
      l = temp;
      s = i;
    }
  }
  double ans = 0;
  rep(i, k) {
    double d = p[s+i] / 2.0 + 0.5;
    ans += d;
  }
  cout << setprecision(15) << ans << endl;
  
}

int main() {
  solve();
  return 0;
}