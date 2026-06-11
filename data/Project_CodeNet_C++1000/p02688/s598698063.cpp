#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using ll = long long;
using namespace std;

int main() {
  int n, k, d;
  int as[105] = {};
  int index;
  cin >> n >> k;
  rep(i, k) {
    cin >> d;
    rep(j, d) {
      cin >> index;
      as[index]++;
    }
  }
  int count = 0;
  for (int j = 1; j <= n; j++) {
    if (as[j] == 0) {
      count++;
    }
  }
  cout << count << endl;
  return 0;
}