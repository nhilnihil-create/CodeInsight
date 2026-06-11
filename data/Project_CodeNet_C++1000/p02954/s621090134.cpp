#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  int n = s.size();

  vector<int> res(n, 0);
  int r = 0;
  rep(i, n) {
    if (s[i] == 'R') ++r;
    else {
      res[i] += r / 2;
      res[i-1] += r - r / 2;
      r = 0;
    }
  }
  int l = 0;
  for (int i = n-1; i >= 0; --i) {
    if (s[i] == 'L') ++l;
    else {
      res[i] += l / 2;
      res[i+1] += l - l / 2;
      l = 0;
    }
  }
  rep(i, n-1) printf("%d ", res[i]);
  printf("%d\n", res[n-1]);
  return 0;
}