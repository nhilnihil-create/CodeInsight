#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (ll i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9;
int main() {
  ll N, D, A;
  cin >> N >> D >> A;
  vector<P> X(N);
  REP(i, N) cin >> X[i].first >> X[i].second;
  sort(X.begin(), X.end());
  ll ans = 0, nowbomb = 0;
  queue<P> que;
  REP(i, N) {
    while (!que.empty()) {
      if (que.front().first < X[i].first) {
        nowbomb -= que.front().second;
        que.pop();
      } else {
        break;
      }
    }
    if (X[i].second <= nowbomb * A) continue;
    ll num = X[i].second - nowbomb * A;
    num = (num + A - 1) / A;
    ans += num, nowbomb += num;
    que.push(P(X[i].first + 2 * D, num));
  }
  cout << ans << endl;
}