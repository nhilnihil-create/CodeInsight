#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  ll n;
  cin >> n;

  for (int i = 0; i <= n; i++) {
    int cost = i * 1.08;
    if (cost == n) {
      cout << i << endl;
      return 0;
    }
  }

  cout << ":(" << endl;
}
