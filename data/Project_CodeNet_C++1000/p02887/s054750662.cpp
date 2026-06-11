#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int ans = 0;
  char cur = '_';
  rep(i, N) {
    if (cur != S[i]) {
      ans++;
      cur = S[i];
    }
  }
  cout << ans << '\n';
  return 0;
}