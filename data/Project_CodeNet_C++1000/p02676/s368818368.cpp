/*input
7
nikoandsolstice
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int k;
  string s;
  cin >> k >> s;
  int mi = min(k, (int)s.size());
  rep(i, mi) cout << s[i];
  if (s.size() > k) cout << "...";
  cout << endl;
}