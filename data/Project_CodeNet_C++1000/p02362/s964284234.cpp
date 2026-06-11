#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> Q;

ll v, e, r, s[2000], t[2000], d[2000], dp[1001], INF = 1e9;

bool search() {
  for (ll i = 0; i < v; i++) dp[i] = INF;
  dp[r] = 0;
  for (ll i = 0; i < v; i++) {
    bool ok = true;
    for (ll j = 0; j < e; j++) {
      if (dp[s[j]] == INF) continue;
      if (dp[t[j]] > dp[s[j]] + d[j]) {
        dp[t[j]] = dp[s[j]] + d[j];
        ok = false;
        if (i == v-1) return true;
      }
    }
    if (ok) break;
  }
  return false;
}

int main() {
  scanf("%lld%lld%lld", &v, &e, &r);
  for (ll i = 0; i < e; i++) scanf("%lld%lld%lld", &s[i], &t[i], &d[i]);
  if (search()) {
    printf("NEGATIVE CYCLE\n");
  } else {
    for (ll i = 0; i < v; i++) {
      if (dp[i] == INF) printf("INF\n");
      else printf("%lld\n", dp[i]);
    }
  }
}

