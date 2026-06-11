#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int k;
  cin >> k;
  int ans = 0;
  for (int i = 0; i < k; i++) {
    ans = (ans * 10 + 7) % k;
    if (ans == 0) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
