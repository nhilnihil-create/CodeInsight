#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double EPS = 1e-10;


int main(void) {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  ll num = 0;
  map<int, int> m;
  rep(i, N) {
    m[A[i]]++;
  }
  for (auto itr = m.begin(); itr != m.end(); ++itr) {
    num += (ll) itr->second * (itr->second - 1) / 2;
  }

  ll before, after;
  rep(i, N) {
    ll val = m[A[i]];
    before = val * (val - 1) / 2;
    after = (val - 1) * (val - 2) / 2;
    cout << num + after - before << endl;
  }
  
  return 0;
}