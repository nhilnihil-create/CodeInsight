#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  vector<ll> sum(n+1);
  rep(i,n) sum[i+1] = sum[i] + a[i];
  ll mx = sum[n];
  ll ans = mx;
  rep(i,n-1) {
    ll l = sum[i+1];
    ll r = mx - l;
    ans = min(ans, abs(l - r));
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}