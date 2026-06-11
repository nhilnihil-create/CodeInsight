#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll MOD = 1000000007;


int main() {
  int n;
  cin >> n;

  int x = 0, y = 0, z = 0;
  ll ans = 1;
  rep(i, n) {
    int a;
    cin >> a;

    ll product = 0;
    int idx = -1;
    if (a == x) {product++; idx = 0;}
    if (a == y) {product++; idx = 1;}
    if (a == z) {product++; idx = 2;}

    if (idx == -1) {
			cout << "0" << endl;
			return 0;
		}

    if (idx == 0) x++;
    if (idx == 1) y++;
    if (idx == 2) z++;

    ans *= product;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
