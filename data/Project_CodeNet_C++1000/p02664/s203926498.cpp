#include <bits/stdc++.h>
using namespace std;
template <typename T> T read() { T a; cin >> a; return a; }

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  auto s = read<string>();
  for (auto c : s) cout << (c == '?' ? 'D' : c);
  return 0;
}
