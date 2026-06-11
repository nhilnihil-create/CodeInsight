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

  int n, m;
  string s;
  cin >> n >> m >> s;
  reverse(s.begin(), s.end());

  vector<int> rec;

  int p = 0, pbefore = 0;
  while (p != n) {
    pbefore = p;
    for (int i = min(n-p, m); i > 0; i--) {
      if ((char)s[p + i] == '0') {
        p += i;
        rec.emplace_back(i);
        //cout << i << endl;
        break;
      }
    }
    if (pbefore == p) {
      cout << -1 << endl;
      return 0;
    }
  }

  for (int i = rec.size()-1; i >= 0; i--) cout << rec[i] << " ";
  cout << endl;
}