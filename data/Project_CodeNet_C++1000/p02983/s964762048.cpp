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

const int N = 2019;

void solve() {
  ll l, r;
  cin >>l >> r;
  ll m = min(r, l + N);
  ll ans = N;
  for (ll i = l; i <= m; i++) {
    for(ll j = i + 1; j <= m; j++) {
      ans = min(ans, (i * j) % N);
    }
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}