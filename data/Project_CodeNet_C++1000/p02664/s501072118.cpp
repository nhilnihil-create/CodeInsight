#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  for (auto &c : s) {
    if (c == '?') {
      c = 'D';
    }
  }
  cout << s << "\n";
  return 0;
}
