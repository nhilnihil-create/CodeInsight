#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s, t;
  cin >> s >> t;
  ll res = 0;
  rep(i, 3) {
    if (s.at(i) == t.at(i)) res++;
  }
  cout << res << endl;
}