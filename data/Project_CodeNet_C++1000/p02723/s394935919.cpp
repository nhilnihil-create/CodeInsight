#include <bits/stdc++.h>

#ifdef STEVEN
#define pp(...) cerr << "\t[" << #__VA_ARGS__ << "]:\t", dbg_out(__VA_ARGS__)
#define ppp(x) cerr << x << "\n"
#else
#define pp(...)
#define ppp(...)
#endif
using namespace std;
// ====

typedef long long ll;
const int MAXN = 1000100;

int main() {
  string s;
  cin >> s;
  if (s.size() == 6 && s[2] == s[3] && s[4] == s[5]) cout << "Yes\n";
  else cout << "No\n";
}
