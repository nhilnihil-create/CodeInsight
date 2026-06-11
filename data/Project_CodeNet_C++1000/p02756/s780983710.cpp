#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // 前後をflagで管理、1の時前を向いている
  string S;
  cin >> S;
  list<char> T;
  rep(i, sz(S)) T.push_back(S[i]);
  int Q;
  cin >> Q;
  bool flag = 1;
  rep(i, Q) {
    int A;
    cin >> A;
    if (A == 1) {
      flag ^= 1;
    } else {
      int F;
      char C;
      cin >> F >> C;
      F = 2 - F;
      if (flag^F == 0) {
        T.push_front(C);
      } else {
        T.push_back(C);
      }
    }
  }
  if (flag == 0) reverse(T.begin(), T.end());
  auto itr = T.begin();
  for (int i = 0; i < sz(T); i++) {
    cout << *itr;
    ++itr;
  }
  cout << '\n';
  return 0;
}