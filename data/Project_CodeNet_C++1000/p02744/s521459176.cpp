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

void dfs(vector<char> &a, ll v) {
  if (a.size() == n) {
    //処理
    // DEBUGS(a);
    REP(i, n) { cout << a[i]; }
    cout << endl;
    return;
  }
  if (a.empty()) {
    a.push_back('a');
    dfs(a, 1);
  } else {
    for (ll i = 0; i < v + 1; i++) {
      a.push_back('a' + i);
      dfs(a, max(v, i+1));
      a.pop_back();
    }
  }
}

int main() {
  cin >> n;
  vector<char> a;
  dfs(a, 0);
  return 0;
}
