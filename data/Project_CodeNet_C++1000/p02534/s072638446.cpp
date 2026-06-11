#include <bits/stdc++.h>

#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, int>;

int main() {
  int k;
  cin >> k;
  string s = "ACL";
  rep(_, k - 1) s += "ACL";
  cout << s << endl;
  return 0;
}