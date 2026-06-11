#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const int INF = (1 << 29);

int main()
{
  int N;
  cin >> N;
  vector<pair<ll, int>> A(N);
  rep(i, N)
  {
    ll a;
    cin >> a;
    A.at(i) = make_pair(a, i);
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 0));
  rep(i, N)
  {
    rep(l, i + 1)
    {
      dp.at(i + 1).at(l + 1) = max(dp.at(i + 1).at(l + 1), dp.at(i).at(l) + A.at(i).first * (A.at(i).second - l));
      dp.at(i + 1).at(l) = max(dp.at(i + 1).at(l), dp.at(i).at(l) + A.at(i).first * (N - i + l - 1 - A.at(i).second));
    }
  }
  ll ans = 0;
  rep(l, N + 1)
  {
    ans = max(ans, dp.at(N).at(l));
  }
  cout << ans << endl;
}