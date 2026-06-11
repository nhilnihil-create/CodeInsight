#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int A, B;
  cin >> A >> B;
  for (int i = 1; i < 1100; i++) {
    if ((i*8/100 == A) && (i*10/100 == B)) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}