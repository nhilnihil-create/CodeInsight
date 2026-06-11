#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n, m, sum = 0;
  cin >> n >> m;
  rep(i, m) {
    int x;
    cin >> x;
    sum += x;
  }
  if (sum > n) cout << -1 << endl;
  else cout << n - sum << endl;
}