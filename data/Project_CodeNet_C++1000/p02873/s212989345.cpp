#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int a[500009];
string s;

int rec(int i) {
  if (a[i] != -1) return a[i];

  if (i == 0) {
    if (s[i] == '<') return a[i] = 0;
    else return a[i] = rec(i+1) + 1;
  }

  if (i == s.size()) {
    if (s[i-1] == '>') return a[i] = 0;
    else return a[i] = a[i-1] + 1;
  }

  if (s[i-1] == '>' && s[i] == '<') return a[i] = 0;
  if (s[i-1] == '<' && s[i] == '<') return a[i] = a[i-1] + 1;
  if (s[i-1] == '>' && s[i] == '>') return a[i] = rec(i+1) + 1;
  if (s[i-1] == '<' && s[i] == '>') return a[i] = max(a[i-1] + 1, rec(i+1) + 1);
  return 0;
}

int main() {
  cin >> s;
  int n = s.size() + 1;
  rep(i, n) a[i] = -1;
  rep(i, n) rec(i);
  ll ans = 0;
  rep(i, n) ans += a[i];
  cout << ans << endl;
  return 0;
}