#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  string s;
  cin >> n >> s;
  bool echo = true;
  if (n % 2) echo = false;
  rep(i, n/2) if (s[i] != s[n/2+i]) echo = false;
  if (echo) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}