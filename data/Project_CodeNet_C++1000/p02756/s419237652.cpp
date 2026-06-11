#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;

const long double EPS = 1e-10;
const long long INF = 1e18;
const int MOD = (int)1e9 + 7;
const long double PI = acos(-1.0L);

int main() {
  list<char> S;
  string s;
  cin >> s;
  rep(i, s.size()) S.push_back(s[i]);
  int q;
  cin >> q;
  bool seq = true;
  rep(i, q) {
    int op;
    cin >> op;
    if (op == 1) {
      seq = !seq;
    } else {
      int func;
      char c;
      cin >> func >> c;
      if (func == 1) {
        if (seq) {
          S.push_front(c);
        } else {
          S.push_back(c);
        }
      } else {
        if (seq) {
          S.push_back(c);
        } else {
          S.push_front(c);
        }
      }
    }
  }
  if (!seq) S.reverse();
  for (char c : S) cout << c;
  cout << endl;

  return 0;
}