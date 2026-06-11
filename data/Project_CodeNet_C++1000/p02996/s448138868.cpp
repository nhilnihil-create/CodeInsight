#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* clang-format off */
#define MOD 1000000007
#define INF 1000000000
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(a) (a).begin(), (a).end()
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
#endif
/* clang-format on */

int main() {
  vector<pair<ll, ll>> task;
  ll n;
  cin >> n;
  REP(i, n) {
    ll a, b;
    cin >> a >> b;
    task.push_back(make_pair(b, a));
  }
  sort(ALL(task));
  ll t = 0;
  REP(i, n) {
    t += task[i].second;
    if (t > task[i].first) {
      cout << "No"
           << "\n";
      return 0;
    }
  }
  cout << "Yes" << "\n";
  return 0;
}
