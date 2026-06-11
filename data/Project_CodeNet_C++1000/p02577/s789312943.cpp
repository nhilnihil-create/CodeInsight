#include <bits/stdc++.h>
using namespace std;
template<class C>constexpr int sz(const C&c){return int(c.size());}
using ll=long long;constexpr const char nl='\n',sp=' ';

int main() {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  // freopen("err.txt", "w", stderr);
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string S;
  cin >> S;
  int sm = 0;
  for (char c : S) sm += c - '0';
  cout << (sm % 9 == 0 ? "Yes" : "No") << nl;
  return 0;
}
