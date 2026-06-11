#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> as(n);
  vector<int> bs(n);
  rep(i, n) {
    cin >> as[i];
    bs[i] = as[i];
  }
  sort(bs.begin(), bs.end());
  rep(i, n) {
    if (as[i] == bs[n - 1]) {
      cout << bs[n - 2] << endl;
    } else {
      cout << bs[n - 1] << endl;
    }
  }

  return 0;
}
