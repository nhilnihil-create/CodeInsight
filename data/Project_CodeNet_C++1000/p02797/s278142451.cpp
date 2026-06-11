#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MAX = 1e9;

int main() {
  ll n, k, s;
  cin >> n >> k >> s;

  vector<ll> ans(n);
  for (int i = 0; i < k; i++) ans[i] = s;
  if (s == MAX) {
    for (int i = k; i < n; i++) ans[i] = s - 1;
  } else {
    for (int i = k; i < n; i++) ans[i] = s + 1;
  }

  for (int i = 0; i < n; i++) {
    printf("%ld ", ans[i]);
  }
  printf("\n");
}
