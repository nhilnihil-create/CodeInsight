#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

bool dbgflag = false;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k, r, s, p;
  cin >> n >> k >> r >> s >> p;

  string str;
  cin >> str;
  string rec = "";

  int ans = 0;

  for (int i = 0; i < n; i++) {
    //cout << str[i] << endl;
    if (i < k) {
      ans += ((str[i] == 'r') ? p : ((str[i] == 's' ? r : s)));
      rec += str[i];
    }
    else {
      if (str[i] == rec[i-k]) {
        rec += 'x';
        continue;
      }
      else {
        ans += ((str[i] == 'r') ? p : ((str[i] == 's' ? r : s)));
        rec += str[i];
      }
    }
  }
  cout << ans << endl;
}
