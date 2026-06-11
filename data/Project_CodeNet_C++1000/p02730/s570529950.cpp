#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

string rev(string str) {
  reverse(str.begin(), str.end());
  return str;
}

bool evaluate(string str) {
  if (str != rev(str)) return false;
  int half = (str.size() - 1) / 2;

  string f = str.substr(0, half);
  if (f != rev(f)) return false;

  string s = str.substr(half + 1);
  if (s != rev(s)) return false;
  return true;
}

int main() {
  string s;
  cin >> s;
  string ans = evaluate(s) ? "Yes" : "No";
  cout << ans << endl;
}
