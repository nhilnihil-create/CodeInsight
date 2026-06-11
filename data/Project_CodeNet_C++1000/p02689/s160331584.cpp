#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using ll = long long;
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> hs(n);
  vector<bool> cs(n, true);
  rep(i, n) { cin >> hs[i]; }
  int a, b;
  rep(i, m) {
    cin >> a >> b;
    if (hs[a - 1] <= hs[b - 1]) {
      cs[a - 1] = false;
    }
    if (hs[b - 1] <= hs[a - 1]) {
      cs[b - 1] = false;
    }
  }
  int count = 0;
  rep(i, n) {
    if (cs[i]) {
      count++;
    }
  }
  cout << count << endl;
  return 0;
}