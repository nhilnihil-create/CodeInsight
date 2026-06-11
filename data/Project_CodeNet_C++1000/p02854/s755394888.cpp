#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<vector<int>>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e18
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> a(N);
  REP(i, N) cin >> a[i];
  vector<ll> s(N + 1, 0);
  REP(i, N) s[i + 1] = s[i] + a[i];
  ll ans = INF;
  for (int i = 0; i < N;i++){
    ll sa = abs(s[N] - s[i + 1] * 2);
    ans = min(ans, sa);
  }
  cout << ans << endl;

  return 0;
}