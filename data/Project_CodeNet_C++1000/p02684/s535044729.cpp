/*input
4 5
3 2 4 1
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int D = 60; // log(MAX_K)
const int MAX_N = 200005;
int to[D][MAX_N];

int main() {
  int n; ll k;
  cin >> n >> k;
  rep(i, n) {
    cin >> to[0][i];
    to[0][i]--;
  }
  rep(i, D-1) rep(j, n) {
    to[i+1][j] = to[i][to[i][j]];
  }

  int v = 0;
  // for (int D-1; i >= 0; --i) {
  //   ll l = 1LL<<i;
  //   if (l <= k) {
  //     v = to[i][v];
  //     k -= l;
  //   }
  // }
  rep(i, D) {
    if (k>>i&1) v = to[i][v];
  }
  cout << v+1 << endl;
  return 0;
}