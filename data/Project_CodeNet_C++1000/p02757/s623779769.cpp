#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define revrep(i,n,g) for (int i = n-1; i >= g; i--)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,p;
  string s;
  cin >> n >> p >> s;
  ll ans = 0;
  if (p == 2 || p == 5) {
    revrep(i,n,0) {
      int k = stoi(s.substr(i,1));
      if (k % p == 0) {
        ans += i + 1;
      }
    }
  } else {
    map<int, int> d;
    d[0] = 1;
    int t = 1;
    int c = 0;
    revrep(i,n,0) {
      int k = stoi(s.substr(i,1));
      c += t * k; c %= p;
      t *= 10; t %= p;
      ans += d[c];
      d[c] += 1;
    }
  }
  cout << ans << endl;
  return 0;
}
