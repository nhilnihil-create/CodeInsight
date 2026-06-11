#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> ls(n);
  rep(i, n) cin >> ls[i];
  sort(ls.begin(), ls.end());
  ll count = 0;
  for (int i = 0; i <= n - 3; i++) {
    for (int j = i + 1; j <= n - 2; j++) {
      for (int k = n - 1; j < k; k--) {
        int a = ls[i], b = ls[j], c = ls[k];
        if (c < a + b) {
          count++;
        }
      }
    }
  }
  cout << count << endl;
  return 0;
}