#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  string s;
  cin >> s;
  rep(i, s.size()) {
    if (s[i] == '?')
      cout << 'D';
    else
      cout << s[i];
  }
  cout << endl;
  return 0;
}
