#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for(int i = m, j = 0; i >= 1 && i > j; --i, ++j) {
    cout << j + 1 << ' ' << i + 1 << '\n';
  }
  for(int i = 2 * m, j = m + 1; i >= 1 && i > j; --i, ++j) {
    cout << j + 1 << ' ' << i + 1 << '\n'; 
  }
}