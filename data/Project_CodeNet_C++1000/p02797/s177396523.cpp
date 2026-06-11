#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, k, s;
  cin >> n >> k >> s;

  // k == nなら{s, s, s, ..., s}
  // k == 0なら{s/2+1, s/2+2, s/2+3, ...}
  vector<int> as(n);
  int t = 500 * 1000 * 1000 + 1; 
  for (int &a : as) {
    a = t++;
  }

  for (int i = 0; i < k; i++) {
    as[i] = s;
  }

  cout << as[0];
  for (int i = 1; i < n; i++) {
    cout << ' ' << as[i];
  }

  cout << endl;

  return 0;
}