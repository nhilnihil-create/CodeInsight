#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PI 3.14159265359
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;

  if (n % 2 == 1) {
    rep(i, m) {
      cout << i + 1 << " " << n - i << endl;
    }
  }
  else {
    rep(i, min(n/4, m)) {
      cout << i + 1 << " " << n - i << endl;
    }
    if (n/4 < m) {
      for (int i=n/4; i<m; i++) {
        cout << i + 1 << " " << n - i - 1 << endl;
      }
    }
  }
  
  return 0;
}
