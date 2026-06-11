/*input
2
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int k;
  cin >> k;
  int a = 7%k, b = a;
  for (int i = 1; i <= k; i++) {
    if (b == 0) {
      cout << i << endl;
      return 0;
    }
    b = (b*10%k+a)%k;
  }
  cout << -1 << endl;
}