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
  vector<ll> v(n+1);
  vector<ll> u(n);
  rep(i,n+1) cin >> v[i];
  rep(i,n) cin >> u[i];
  ll ans = 0;
  rep(i,n) {
    ans += min(v[i], u[i]);
    u[i] = max((ll) 0, u[i] - v[i]);
    if (u[i] == 0) continue;
    ans += min(v[i+1], u[i]);
    v[i+1] = max((ll) 0, v[i+1] - u[i]);
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}