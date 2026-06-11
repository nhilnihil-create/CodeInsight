#include <bits/stdc++.h>

using namespace std;

int n;

void f(string s) {
  int len = (int)s.size();
  if (len < n) {
    char mx = 'a';
    for (int i = 0; i < len; i++) {
      mx = max(mx, s[i]);
    }
    for (char c = 'a'; c <= mx + 1; c++) {
      f(s + c);
    }
  } else {
    cout << s << '\n';
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  f("a");
  return 0;
}