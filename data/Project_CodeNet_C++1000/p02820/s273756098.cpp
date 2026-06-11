#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n, k, r, s, p;
  string t;
  cin >> n >> k >> r >> s >> p >> t;
  vector<int> vec(n);
  vector<int> pts = {r, s, p};
  rep(i, n) {
    if (t.at(i) == 'r') vec.at(i) = 2;
    if (t.at(i) == 's') vec.at(i) = 0;
    if (t.at(i) == 'p') vec.at(i) = 1;
  }
  vector<vector<int>> dp(n, vector<int>(3));
  rep(i,k) {
    dp.at(i).at(vec.at(i)) = pts.at(vec.at(i));
    for (int j = i + k; j < n; j += k) {
      for (int m = 0; m < 3; m++) {
        if (vec.at(j) == m) {
          dp.at(j).at(m) = max(dp.at(j-k).at((m+1)%3), dp.at(j-k).at((m+2)%3)) + pts.at(m);
        } else {
          dp.at(j).at(m) = max(dp.at(j-k).at((m+1)%3), dp.at(j-k).at((m+2)%3));
        }
      }
    }
  }
  ll ans = 0;
  for (int i = n-1; i > n-k-1; i--) {
    ans += max(dp.at(i).at(0), max(dp.at(i).at(1), dp.at(i).at(2)));
  }
  cout << ans << endl;
  return 0;
}