#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif
  int N, cnt = 0, flag = false;
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    int x, y;
    cin >> x >> y;
    if (x == y)
      ++cnt;
    else
      cnt = 0;
    if (cnt >= 3) flag = true;
  }
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}