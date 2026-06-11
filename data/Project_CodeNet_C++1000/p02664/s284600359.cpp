#include <bits/stdc++.h>
#define dbg() cerr <<
#define name(x) (#x) << ": " << (x) << ' ' <<

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  for (auto &c : s) {
    if (c == '?') c = 'D';
  }
  cout << s << endl;
}
