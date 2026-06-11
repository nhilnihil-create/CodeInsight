#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, cnt = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if((0 < i && i < 10) || (99 < i && i < 1000) || (9999 < i && i < 100000)) cnt++;
  }
  cout << cnt;
}