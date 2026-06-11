#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int m = 2019;

int main() {
  string S;
  cin >> S;
  vector<int> R(m, 0);
  int n = S.size();
  int sum = 0, x = 1;
  for (int i = n - 1; i >= 0; i--) {
    sum += (S.at(i) - '0') * x;
    sum %= m;
    R.at(sum)++;
    x = x * 10 % m;
  }
  R.at(0)++;

  int ans = 0;
  for (auto r : R) {
    if (r > 1) ans += r * (r - 1) / 2;
  }

  cout << ans << endl;
}
