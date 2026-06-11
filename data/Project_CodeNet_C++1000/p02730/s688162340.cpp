#include <bits/stdc++.h>
using namespace std;

bool pal(string s) {
  string t = s;
  reverse(t.begin(), t.end());
  return s == t;
}

int main() {
  string S;
  cin >> S;
  int N = S.size();
  if (!pal(S)) return cout << "No" << "\n", 0;
  string l = S.substr(0, N / 2);
  string r = S.substr(N / 2 + 1);
  cout << ((pal(l) && pal(r)) ? "Yes" : "No") << "\n";
}