#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF (INT_MAX / 4)
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(a) (a).begin(), (a).end()
/* clang-format off */
#define __DEBUG__
#ifdef __DEBUG__
#define CH_P(a) cout <<"check_point("<<#a<<")" << "\n";
#define DEBUG(x) cout<<#x<<":"<<x<<"\n"
#define DEBUGS(v) cout << #v << ":";for(auto x:v){cout<<x<<" ";}cout<<"\n"
#endif
#ifndef __DEBUG__
#define CH_P(a) 
#define DEBUG(x) 
#define DEBUGS(v) 
#endif /* clang-format on */

vector<int> a(50), b(50), c(50), d(50);
vector<ll> arr;
int n, m, q;
int ans = 0;

void cal_score() {
  int t = 0;
  REP(i, q) {
    if (arr[b[i] - 1] - arr[a[i] - 1] == c[i]) t += d[i];
  }
  ans = max(ans, t);
}


void dfs(vector<ll> &a) {
  if (a.size() == n) {
    //処理
    //DEBUGS(a);
    cal_score();
    return;
  }
  ll s;
  if (arr.empty()) s = 0;
  else
    s = arr[arr.size() - 1];
  for (ll i = s; i < m; i++) {
    a.push_back(i);
    dfs(a);
    a.pop_back();
  }
}

int main() {
  cin >> n >> m >> q;
  REP(i, q) { cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i); }

  dfs(arr);

  cout << ans << endl;
  return 0;
}
