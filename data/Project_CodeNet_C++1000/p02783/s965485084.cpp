#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;
#define ALL(x) x.begin(),x.end()
#define P pair<int,int>
#define mod 1000000007

int main() {
  int h, a;
  cin >> h >> a;
  int ans = h / a;
  if (h % a != 0) ans++;
  cout << ans << endl;

  return 0;
}
