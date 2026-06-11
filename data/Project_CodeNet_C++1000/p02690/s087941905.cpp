#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;

const long double EPS = 1e-10;
const long long INF = 1e18;
const int MOD = (int)1e9 + 7;
const long double PI = acos(-1.0L);

int main() {
  int x;
  cin >> x;
  for (int k = -118; k < 120; k++) {
    for (int i = -118; i < 120; i++) {
      int j = i - k;
      int tmpx = (i * i * i * i * i) - (j * j * j * j * j);
      if (tmpx == x) {
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
  return 0;
}