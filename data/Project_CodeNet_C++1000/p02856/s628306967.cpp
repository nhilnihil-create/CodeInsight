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

  ll m;
  cin >> m;
  ll dig = 0;
  ll dsum = 0;
  for (int i = 0; i < m; i++) {
    ll d, c;
    cin >> d >> c;
    dig += c;
    dsum += c * d;
  }

  cout << ((dsum - 1) / 9) + (dig - 1) << endl;
}
