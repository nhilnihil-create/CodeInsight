#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;

  int l = (n - 1) * (n - 2) / 2;
  if (k > l) {
    cout << -1 << endl;
    return 0;
  }

  vector<pair<int, int>> uv;
  for (int i = 2; i <= n; i++) {
    uv.push_back(make_pair(1, i));
  }

  int cnt = 0;
  int c = 0;
  while (cnt < l - k) {
    int a = c / (n - 1) + 2;
    int b = c % (n - 1) + 2;
    if (a < b) {
      uv.push_back(make_pair(a, b));
      cnt++;
    }
    c++;
  }

  cout << uv.size() << endl;
  rep(i, uv.size()) printf("%d %d\n", uv[i].first, uv[i].second);
  return 0;
}