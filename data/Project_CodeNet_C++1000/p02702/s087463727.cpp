#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < n; i++)
#define revrep(i,n,g) for (int i = n-1; i >= g; i--)
using namespace std;
using ll = long long;

ll solve(string s, int p) {
  map<int, ll> d;
  d[0] = 1;
  int c,t;
  c = 0; t = 1;
  ll ans = 0;
  revrep(i, s.size(), 0) {
    int a = atoi(s.substr(i,1).c_str());
    c += a * t;
    c %= p;
    ans += d[c];
    d[c] += 1;
    t *= 10;
    t %= p;
  }
  return ans;
}

int main() {
  string s;
  cin >> s;
  ll a = solve(s, 2019);
  cout << a << endl;
  return 0;
}
