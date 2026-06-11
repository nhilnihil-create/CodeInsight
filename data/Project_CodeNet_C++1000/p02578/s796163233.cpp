#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];

  ll sum = 0;
  rep2(i, 1, n) {
    if (v[i - 1] > v[i]) {
      sum += v[i - 1] - v[i];
      v[i] = v[i - 1];
    }
  }
  cout << sum << endl;
  return 0;
}