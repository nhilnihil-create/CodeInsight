#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  char a, b;
  cin >> a >> b;
  string sa, sb;
  rep(i, (int)(b-'0')) sa += a;
  rep(i, (int)(a-'0')) sb += b;
  cout << min(sa, sb) << endl;
  return 0;
}