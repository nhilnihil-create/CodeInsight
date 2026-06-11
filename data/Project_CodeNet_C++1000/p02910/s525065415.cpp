#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;

int main() {
  string s;
  cin >> s;
  bool ok = true;
  rep(i,s.size()) {
    if (i % 2 == 0) {
      if (s.at(i) == 'L') ok = false;
    } else {
      if (s.at(i) == 'R') ok = false;
    }
  }
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
