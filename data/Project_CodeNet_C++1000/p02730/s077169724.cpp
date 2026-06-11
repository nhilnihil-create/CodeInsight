#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  auto f = [&](string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
  };
  cout << ((f(S) && f(S.substr((N + 3) / 2 - 1))) ? "Yes" : "No") << "\n";
}