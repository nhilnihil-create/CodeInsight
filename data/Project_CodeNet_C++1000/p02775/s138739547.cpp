#include <iostream>
using namespace std;
using ll = long long;
#define in(v) v; cin >> v;
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)
constexpr ll INF = 5e18;

int main() {
  string N; cin >> N;

  ll dp[2] = {0, 1};
  rep(i, N.size()) {
    ll dp2[2] = {INF, INF};
    rep(carry, 2) {
      int n = (N[i]-'0') + carry;
      rep(j, 10)
        if (j >= n) dp2[carry] = min(dp2[carry], j + (j-n) + dp[false]);
        else dp2[carry] = min(dp2[carry], j + (10+j-n) + dp[true]);
    }
    swap(dp, dp2);
  }
  cout << dp[false] << endl;
  return 0;
}
