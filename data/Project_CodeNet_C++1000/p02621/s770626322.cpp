#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;
using p = pair<int,int>;
int main() {
  int a; cin >> a;
  int ans = 0;
  ans = a + a * a + a * a * a;
  cout << ans << endl;

	return 0;
}

