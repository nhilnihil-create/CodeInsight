#include <bits/stdc++.h>
using namespace std;

int n, m;
int main() {
  cin >> n >> m;
  if (n % 2 == 1) {
    for (int i = 0; i < m; ++i) {
      cout << i + 1 << ' ' << n - i << endl;
    } 
  } else {
    for (int i = 0; i < min(m, n / 4); ++i) {
      cout << i + 1 << ' ' << n - i << endl;
    }
    for (int i = n / 4; i < m; ++i) {
      cout << i + 1 << ' ' << n - i - 1 << endl;
    }
  }
}