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

ll func(ll x, ll k) {
  return min(x, min(x%k, k - (x%k)));
}

void solve() {
  ll n, k;
  cin >> n >> k;
  ll x = n;
  ll ans = func(x, k);
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}