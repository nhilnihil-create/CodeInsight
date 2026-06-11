#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  int H,A;cin >> H >> A;
  int ans = 0;
  if(H%A == 0) ans = H / A;
  else ans = H / A + 1;
  cout << ans << endl;
	return 0;
}

