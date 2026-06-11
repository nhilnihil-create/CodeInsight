#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

const int INF = 100000005;

int main() {
  int n;
  cin >> n;
  vector<int> as(n, INF);
  vector<int> bs(n - 1);
  rep(i, n - 1) { cin >> bs[i]; }
  for (int i = n - 2; 0 <= i; i--) {
    as[i + 1] = min(bs[i], as[i + 1]);
    as[i] = min(bs[i], as[i]);
  }
  int sum = 0;
  rep(i, n) { sum += as[i]; }
  cout << sum << endl;
  return 0;
}
