#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll A, B, K;
  cin >> A >> B >> K;
  ll take = min(A, K);
  A -= take;
  K -= take;
  if (K > 0) B -= K;
  if (B < 0) B = 0;
  cout << A << ' ' << B << '\n';
  return 0;
}