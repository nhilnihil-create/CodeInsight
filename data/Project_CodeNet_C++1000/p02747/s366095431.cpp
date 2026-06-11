#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  if (SZ(s) & 1) {
    cout << "No\n";
  }
  else {
    bool ok = true;
    for (int i = 0; i < SZ(s); i++) {
      if (i % 2 == 0) {
        ok &= s[i] == 'h';
      }
      else {
        ok &= s[i] == 'i';
      }
    }
    cout << (ok ? "Yes\n" : "No\n");
  }
} 