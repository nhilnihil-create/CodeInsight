#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  string s;
  cin >> n >> s;
  rep(i, s.size()) {
    int c = (int)s[i] + n;
    if (c > (int)'Z') c -= 26;
    printf("%c", c);
  }
  printf("\n");
  return 0;
}