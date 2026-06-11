/*
  no pain, no gain
*/

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2,fma")
#include <bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define szof(s) (int)s.size()
#define all(s) s.begin(), s.end()
#define pii pair<int, int>
#define all(s) s.begin(), s.end()
#define prev myrza4321
#define y1 myrza1234
#define OK puts("OK")
using namespace std;

const int N = (int)1e5 + 5;
const int INF = 0x3f3f3f3f;


struct S {
  int l, r, x, cost;
  S(int l_, int r_, int x_, int cost_) {
    l = l_, r = r_, x = x_, cost = cost_;
  }
};

int a[11];
int n, mx, Q, ans = 0;
vector <S> q;

void dfs(int pos = 1) {
  if (pos > n) {
    int sum = 0;
    for (auto c : q) {
      if (a[c.r] - a[c.l] == c.x) {
        sum += c.cost;
      }
    }
    ans = max(ans, sum);
    return;
  }
  for (int i = 1; i <= mx; i++) {
    if (pos > 1 && a[pos - 1] > i) {
      continue;
    }
    a[pos] = i;
    dfs(pos + 1);
  }
}

main() {
  cin >> n >> mx >> Q;
  while (Q--) {
    int l, r, x, cost;
    scanf("%d %d %d %d", &l, &r, &x, &cost);
    q.pb(S(l, r, x, cost));
  }
  dfs();
  cout << ans;
}
