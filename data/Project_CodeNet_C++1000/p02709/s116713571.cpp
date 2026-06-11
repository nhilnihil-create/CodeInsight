

#include <limits>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int n;
ll vs[2020];
pair<ll,int> ps[2020];
ll memo[2020][2020];
bool visited[2020][2020];
ll solve(int tot, int left) {
  ll &res = memo[tot][left];
  if(!visited[tot][left]) {
    visited[tot][left] = true;
    if(tot == 0) {
      res = left == 0 ? 0 : -1;
    } else {
      res = 0;
      int target = tot-1;
      if(left > 0) {
        ll tmp = solve(tot-1, left-1);
        tmp += ps[target].first * (ps[target].second - (left-1));
        res = max(res, tmp);
      }
      int right = tot-left;
      if(right > 0) {
        ll tmp = solve(tot-1, left);
        tmp += ps[target].first * ((n-right) - ps[target].second);
        res = max(res, tmp);
      }
    }
  }
  return res;
}



int main(void) {
  scanf("%d", &n);
  
  REP(i, n) {
    scanf("%lld", &vs[i]);
    ps[i] = make_pair(vs[i], i);
  }
  sort(ps, ps + n);
  reverse(ps, ps + n);
  ll res = 0;
  REP(i, n+1) {
    res = max(res, solve(n, i));
  }
  cout << res << endl;
  return 0;
}
