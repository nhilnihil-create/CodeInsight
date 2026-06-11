#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  int L;
  cin >> L;

  double ans = (L * L * L + 0.0000001) / 27;
  cout << fixed << setprecision(15) << ans;
}
