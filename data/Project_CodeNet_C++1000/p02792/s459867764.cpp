#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
#define INF 1000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

bool dbgflag = false;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<vector<int>>rec(10, vector<int>(10));
  for (int i = 1; i <= n; i++) {
    int t = ((i / 100000 > 0) ? i / 100000 : ((i / 10000 > 0) ? i / 10000 : ((i / 1000 > 0) ? i / 1000 : ((i / 100 > 0) ? i / 100 :((i / 10 > 0) ? i / 10: i)))));
    if (t == 0) cout << i << endl;
    rec[t][i%10]++;
  }  

  ll ans = 0;
  for (int i = 0 ; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      ans += rec[i][j] * rec[j][i];
    }
  }

  cout << ans << endl;
}