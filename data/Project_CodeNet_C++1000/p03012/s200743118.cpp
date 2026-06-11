#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define erep(i, n) for(ll i = 1; i <= (n); i++)
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(void) {
  int n;
  cin >> n;
  vector<int> w(n), s(n+1, 0);
  rep(i,n)cin >> w[i];
  rep(i,n)s[i+1] = s[i] + w[i];
  int ans = 1e9;
  rep(i,n){
    int left = s[i], right = s[n] - s[i];
    mins(ans, abs(right - left));
  }
  cout << ans << '\n';
  return 0;
}