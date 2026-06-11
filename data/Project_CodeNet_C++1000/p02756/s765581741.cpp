#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main() {
  string s;
  int q;
  cin >> s >> q;

  string r;
  bool st = true;
  rep(i, q) {
    int t;
    cin >> t;

    if(t == 1) {
      st = !st;
      continue;
    }

    int f;
    string c;
    cin >> f >> c;

    if((f == 1 && st) || (f == 2 && !st))
      r += c;
    else
      s += c;
  }
  if(st) {
    reverse(r.begin(), r.end());
    cout << r << s;
  } else {
    reverse(s.begin(), s.end());
    cout << s << r;
  }
}
