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
  bool bl = (A <= 9 && B <= 9);
  if (bl) {
    cout << A * B << '\n';  
  } else {
    cout << -1 << '\n';
  }
  return 0;
}