#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;

  int S = s.length();
  vector<int> l(S, 0);

  for (int i = 0; i < S; i++) {
    if (l[i] != 0) continue;
    if (s[i] == 'R') {
      int pos = s.find('L', i);
      for (int j = i; j < pos; j++) {
        if ((pos - j) % 2 == 0)
          l[j] = pos;
        else
          l[j] = pos - 1;
      }
    } else {
      if (s[i - 1] == 'R')
        l[i] = i;
      else if (s[i - 1] == 'L' && s[i - 2] == 'R')
        l[i] = i - 2;
      else
        l[i] = l[i - 2];
    }
  }

  vector<int> ans(S, 0);
  rep(i, S) ans[l[i]]++;
  rep(i, S) printf("%d ", ans[i]);
  printf("\n");
}
