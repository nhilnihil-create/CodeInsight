#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool isPalindrome(string s) {
  string t = s;
  reverse(t.begin(), t.end());
  return s == t;
}

int main() {
  string S;
  cin >> S;
  bool bl = true;
  if (!isPalindrome(S)) bl = false;
  string T = S.substr(0, sz(S)/2);
  if (!isPalindrome(T)) bl = false;
  puts(bl ? "Yes" : "No");
  return 0;
}