#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int x;
  cin >> x;
  for (int i = 0; i < 10011; i++) {
    if (100 * i <= x && x <= 100 * i + 5 * i) {
      cout << 1 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}