
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;


vector<int> g[1000005];
int n;

inline int encode(int u, int v) {
  return u < v ? u*n+v : v*n+u;
}

int vs[1000+1][1000+1];
int st[1000005];
int dp[1000005];

int solve(void) {
  int res = 0;
  memset(dp, -1, sizeof dp);
  REP(i, n) {
    REP(j, n-1) {
      if(i > vs[i][j]) {
        continue;
      }
      int sed = 0;
      st[sed++] = encode(i, vs[i][j]);
      while(sed > 0) {
        int cur = st[--sed];
        if(cur >= 0) {
          if(dp[cur] == -2) {
            return -1;
          } else if(dp[cur] >= 0) {
            continue;
          }
          dp[cur] = -2;
          st[sed++] = ~cur;
          for(int next : g[cur]) {
            st[sed++] = next;
          }
        } else {
          dp[~cur] = 1;
          for(int next : g[~cur]) {
            dp[~cur] = max(dp[~cur], dp[next]+1);
          }
          res = max(res, dp[~cur]);
        }
      }
    }
  }
  return res;
}

int main(void) {
  scanf("%d", &n);
  REP(i, n) {
    REP(j, n-1) {
      scanf("%d", &vs[i][j]);
      --vs[i][j];
      if(j > 0) {
        int u = encode(i, vs[i][j-1]);
        int v = encode(i, vs[i][j]);
        g[u].push_back(v);
      }
    }
  }
  int res = solve();
  cout << res << endl;
  return 0;
}
