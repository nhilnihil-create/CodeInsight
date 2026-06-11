#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<P> as(n);
  rep(i, n) {
    int a;
    cin >> a;
    as[i] = P(a, i + 1);
  }
  sort(as.begin(), as.end());
  rep(i, n) {
    if (i != n - 1) {
      cout << as[i].second << " ";
    } else {
      cout << as[i].second << endl;
    }
  }
  return 0;
}
