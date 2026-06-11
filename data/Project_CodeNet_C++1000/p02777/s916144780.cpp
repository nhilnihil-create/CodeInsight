#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string S;
  string T;
  cin >> S >> T;
  int A, B;
  cin >> A >> B;
  string U;
  cin >> U;
  if (S == U) --A;
  else --B;
  cout << A << ' ' << B << '\n';  
  return 0;
}