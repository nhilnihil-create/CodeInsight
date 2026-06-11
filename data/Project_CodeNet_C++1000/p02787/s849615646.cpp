#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;
#define ALL(x) x.begin(),x.end()
#define P pair<ll,ll>
#define mod 1000000007

int main() {
  int h, n, a, b;
  cin >> h >> n;
  vector<P> magic;
  vector<ll> cost(h + 1, pow(10, 17));
  rep(i, n) {
    cin >> a >> b;
    magic.push_back(P(a, b));
  }
  for (int i = 1; i <= h; i++) {
    for (int j = 0; j < n; j++) {
      if (magic[j].first >= i) {
        cost[i] = min(cost[i], magic[j].second);
      } else {
        cost[i] = min(cost[i], magic[j].second + cost[i - magic[j].first]);
      }
    }
  }
  cout << cost[h] << endl;

  return 0;
}
