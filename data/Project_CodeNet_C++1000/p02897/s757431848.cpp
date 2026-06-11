#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  int n; cin >> n;
  int odd = (n + 1)/2;
  double ans;
  ans = (double)odd/n;



  cout << fixed << setprecision(15) << ans << endl;
	return 0;
}

