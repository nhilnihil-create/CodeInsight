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

ll n;
vector<ll> lun;

void dfs(vector<ll> &a) {
  if (a.size() == n) {
    //処理
    //DEBUGS(a);
    ll t = 0;
    REP(i, a.size()) { t += (ll)pow(10, a.size() - i - 1) * a[i]; }
    lun.push_back(t);
    return;
  }

  if (a.empty()) {
    REP(i, 9) {
      a.push_back(i + 1);
      dfs(a);
      a.pop_back();
    }
  } else {
    for (ll i = a.back() - 1, j = 0; i < 10 && j < 3; i++, j++) {
      if (i < 0) continue;
      a.push_back(i);
      dfs(a);
      a.pop_back();
    }
  }
}

int main() {
  ll k;
  cin >> k;

  REP(i, 10) {
    vector<ll> a;
    n = i + 1;
    dfs(a);
  }
  sort(ALL(lun));
  cout << lun[k - 1] << endl;
  return 0;
}
