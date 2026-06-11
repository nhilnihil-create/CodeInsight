#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
const ll mod = 1000000007;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> k(n);
  int s[3] = {0, 0, 0};
  rep(i, n) {
    int cnt = 0;
    int nc = 4;
    rep(col, 3) {
      if(s[col] == a[i]) {
        cnt++;
        nc = min(nc, col);
      }
    }
    k[i] = cnt;
    if(nc > 3) break;
    dbg(nc);
    s[nc]++;
  }
  ll ans = 1LL;
  rep(i, n) ans = (ans * k[i]) % mod;
  cout << ans << endl;
  return 0;
}