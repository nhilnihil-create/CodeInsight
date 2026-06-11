#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, d;
  cin >> n >> d;
  int a = 2 * d + 1;
  int ans = (n + a - 1) / a;
  cout << ans << endl;
  return 0;
}