#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)

const int N_MAX = 100000 + 1;
int n;
int a[N_MAX];

bool input() {
  if (cin >> n) {
    rep (i, n) cin >> a[i];
    return true;
  }
  return false;
}

int solve() {
  int l[n];
  int lc = 1;
  l[0] = a[0]; 
  rep (i, n) {
    if (l[lc - 1] < a[i]) l[lc++] = a[i];
    auto it = lower_bound(l, l + lc, a[i]);
    if (it != l + lc) *it = a[i];
  }
  return lc;
}

int main() {
  while (input()) {
    cout << solve() << endl;
  }
  return 0;
}