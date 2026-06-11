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
  string S(B, '0'+A); // Aの文字をB回繰り返す
  string T(A, '0'+B);
  cout << min(S, T) << '\n';
  return 0;
}