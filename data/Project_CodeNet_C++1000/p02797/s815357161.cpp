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
  int n, k, s;
  cin >> n >> k >> s;
  if (s == 1e9) {
    for (int i = 0; i < k; i++) {
      cout << s << ' ';
    }
    for (int i = 0; i < n - k; i++) {
      cout << 1 << ' ';
    }
    cout << '\n';
  }
  else {
    for (int i = 0; i < k; i++) {
      cout << s << ' ';
    }
    for (int i = 0; i < n - k; i++) {
      cout << s + 1 << ' ';
    }
    cout << '\n';
  }
} 