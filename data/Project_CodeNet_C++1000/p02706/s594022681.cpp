#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, m;
  cin >> n >> m;

  int days = 0;

  rep(i, m) {
    int a;
    cin >> a;
    days += a;
  }

  cout << max(-1, n - days) << endl;

  return 0;
}
