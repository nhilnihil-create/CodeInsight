#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> as(n);
  rep(i, n) cin >> as[i];
  int sum = as[0];
  rep(i, n - 1) { sum = sum ^ as[i + 1]; }
  rep(i, n) {
    int ans = sum ^ as[i];
    printf("%d%c", ans, i == n - 1 ? '\n' : ' ');
  }
  return 0;
}
