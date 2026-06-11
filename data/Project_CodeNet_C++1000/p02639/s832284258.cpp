/*input
0 2 3 4 5
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  for (int i = 1; i <= 5; ++i) {
    int x;
    cin >> x;
    if (x == 0) {
      cout << i << endl;
      return 0;
    }
  }
}