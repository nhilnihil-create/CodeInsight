#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 10000000000
using namespace std;
using ll = long long int;
using pll = pair<long long, long long>;

int main () {
  int N;
  cin >> N;

  vector<ll> X(N, 0);
  vector<ll> L(N, 0);
  vector<pll> A(N, make_pair(0, 0));
  rep(i, N) {
    cin >> X.at(i) >> L.at(i);
    A.at(i).first = X.at(i) - L.at(i);
    A.at(i).second = X.at(i) + L.at(i);
  }
  sort(A.begin(), A.end(), [](pll a, pll b) {return a.second < b.second;});
  int ans = 0;
  int t = -INF;
  rep(i, N) {
    if (t <= A.at(i).first) {
      ans++;
      t = A.at(i).second;
    }
  }
  cout << ans;
}