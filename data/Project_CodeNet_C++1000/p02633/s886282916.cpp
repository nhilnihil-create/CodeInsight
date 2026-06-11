#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int x;
  cin >> x;
  for (int i = 1; ; i++) {
    if ((x * i) % 360 == 0) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}