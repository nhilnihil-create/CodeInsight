#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  t.pop_back();
  cout << ((s == t) ? "Yes" : "No") << endl;
  return 0;
}