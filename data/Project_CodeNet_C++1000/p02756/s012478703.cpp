#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define repi(n) for (long long i = 0; i < (n); ++i)
#define repj(n) for (long long j = 0; j < (n); ++j)
#define repk(n) for (long long k = 0; k < (n); ++k)
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(itr) for (auto&& v : (itr))
#define updatemax(t, v) (t = std::max(t, (v)))
#define updatemin(t, v) (t = std::min(t, (v)))

int main() {
  string s;
  cin >> s;
  deque<char> q;
  itr(s) q.push_back(v);
  bool rev = false;
  int n;
  cin >> n;
  repi(n) {
    int com;
    cin >> com;
    if (com == 1) {
      rev = !rev;
      continue;
    }
    int f;
    char c;
    cin >> f >> c;
    if ((f == 1 && !rev) || (f == 2 && rev)) {
      q.push_front(c);
    } else {
      q.push_back(c);
    }
  }
  if (rev) {
    for (auto i = q.rbegin(); i != q.rend(); ++i) cout << *i;
  } else {
    itr(q) cout << v;
  }
  cout << endl;
}
