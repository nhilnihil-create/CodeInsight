#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    vector<int> A(5);
    rep(i, 5) cin >> A[i];
      for (int i = 1; i <= 5; i++) {
          if (!count(A.begin(), A.end(), i)) {
              cout << i << '\n';
              break;
          }
      }
    return 0;
    // ll, 0, -, 1i, for s&g
}