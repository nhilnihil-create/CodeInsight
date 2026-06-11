#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

int main() {
  string s;
  cin >> s;

  if (s[2] == s[3] && s[4] == s[5]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}