#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin >> s;
  vector <ll> v(26, 0);
  rep(i, s.size()) {
    ll num = s.at(i)-'A';
    v.at(num)++;
  }
  ll flag = 0;
  rep(i, 26) {
    if (v.at(i) == 2) flag++;
  }
  if (flag == 2) cout << "Yes" << endl;
  else cout << "No" << endl;
}