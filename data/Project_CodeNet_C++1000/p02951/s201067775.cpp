#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair <int, int>;
const double PI = acos(-1);
const ll MOD = 1000000007;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  int ans = C - (A - B);

  if(ans > 0) cout << ans << endl;
  else cout << "0" << endl;

}
