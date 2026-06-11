#include <bits/stdc++.h>
using namespace std;

const int MN = 200012;

int n, k;
int a[MN];

bool check(int x) {
  int ctr = k;
  for (int i = 0; i < n; i++) {
    int cuts = (a[i] - 1) / x;
    if (cuts > ctr)
      return false;
    ctr -= cuts;
  }
  return true;
}

int main (void) {
  ios::sync_with_stdio(false);cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int res = *max_element(a, a + n);
  int lo = 1, hi = res;
  while (lo <= hi) {
    int mi = (lo + hi) / 2;
    if (check(mi)) {
      hi = mi - 1;
      res = mi;
    } else {
      lo = mi + 1;
    }
  }
  cout << res << '\n';
  return 0;
}

