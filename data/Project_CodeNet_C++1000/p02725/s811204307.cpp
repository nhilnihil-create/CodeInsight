#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int k, n;
  cin >> k >> n;
  vector<int> as(n);
  for (int &a : as) cin >> a;

  int mx = 0;
  mx = k - as[n - 1] + as[0];
  for (int i = 1; i < n; i++) {
    mx = max(mx, as[i] - as[i - 1]);
  }

  cout << k - mx << endl;
  return 0;
}