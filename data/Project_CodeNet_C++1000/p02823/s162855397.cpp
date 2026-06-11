#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

ll n, a, b, ans;

int main() {
  cin >> n >> a >> b;
  if (a > b) swap(a, b);
  ans = (b-a)/2;
  if ((b-a) % 2 == 1) ans = min(a, n-b+1) + (b-a-1)/2;
  cout << ans << endl;
  return 0;
}
