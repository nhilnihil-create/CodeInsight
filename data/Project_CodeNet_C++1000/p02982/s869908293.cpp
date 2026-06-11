#include <bits/stdc++.h>
#define IOS                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
ll bpow(ll b, ll p, ll m = 1000000007LL) {
  ll rt = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      rt = rt * b % m;
  return rt;
}
int x[105][105];
int main() {
  IOS;
  int n, d;
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < d; j++) {
      cin >> x[i][j];
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ll s = 0;
      for (int k = 0; k < d; k++)
        s += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
      ll ns = sqrt(s);
      ns *= ns;
      if (s == ns)
        cnt++;
    }
  }
  cout << cnt << endl;
}
