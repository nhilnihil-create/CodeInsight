#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int h1, h2, m1, m2, k, ans;
  cin >> h1 >> m1 >> h2 >> m2 >> k;
  ans = (h2 - h1)*60 + m2 - m1 - k;
  cout << ans << endl;
  
return 0;
}