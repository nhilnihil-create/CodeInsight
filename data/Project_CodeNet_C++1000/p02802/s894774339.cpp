#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<bool> ok(n, false);
  vector<int> penas(n, 0);
  rep(i, m) {
    int p;
    string s;
    cin >> p >> s;
    p--;
    if (s == "WA") {
      if (!ok[p]) {
        penas[p]++;
      }
    }
    if (s == "AC") {
      ok[p] = true;
    }
  }
  int ac = 0;
  int pena = 0;
  rep(i, n) {
    if (ok[i]) {
      ac++;
      pena += penas[i];
    }
  }
  cout << ac << " " << pena << endl;
  return 0;
}
