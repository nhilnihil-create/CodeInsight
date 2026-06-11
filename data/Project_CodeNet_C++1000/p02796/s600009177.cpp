#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, x, l;
  cin >> n;
  vector<P> xl;
  rep(i, n) {
    cin >> x >> l;
    xl.emplace_back(x + l, x - l);
  }
  sort(xl.begin(), xl.end());

  int cnt = 0, p = -1001001001;
  for (auto a : xl) {
    if (p <= a.second) {
      cnt++;
      p = a.first;
    }
  }
  cout << cnt << endl;

  return 0;
}
