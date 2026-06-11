#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> n >> s;
  if (n % 2 == 0 && s == s.substr(n / 2) + s.substr(n / 2)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}