#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string S;
  cin >> S;
  bool bl = true;
  string T = S;
  reverse(T.begin(), T.end());
  if (S != T) bl = false;
  int right = sz(S) / 2 - 1;
  for (int i = 0; i < right; i++) {
    if (S[i] != S[right-i]) bl = false;
  }
  puts(bl ? "Yes" : "No");
  return 0;
}