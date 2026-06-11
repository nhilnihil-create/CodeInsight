#include <bits/stdc++.h>
using namespace std;

const int MN = 200012;

int n;
int pf[MN];
char s[MN];

int main (void) {
  ios::sync_with_stdio(false);cin.tie(0);
  cin >> n >> s;
  int res = n;
  // prefix sums of red stones
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == 'R')
      pf[i] = pf[i - 1] + 1;
    else
      pf[i] = pf[i - 1];
  }
  res = min(pf[n], n - pf[n]);
  for (int i = 1; i <= n; i++) {
    int rl = pf[i], wl = i - pf[i];
    int rr = pf[n] - pf[i], wr = n - rl - wl - rr;
    int mv = min(wl, rr);
    res = min(res, mv + (i - rl - mv) + (n - i - wr - mv));
  }
  cout << res << '\n';
  return 0;
}

