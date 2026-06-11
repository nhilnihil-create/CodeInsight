#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin >> s;
  bool flag = 1;
  rep(i, 3) {
    if (s.at(i) == s.at(i+1)) flag = 0;
  }
  if (flag) cout << "Good" << endl;
  else cout << "Bad" << endl;
}