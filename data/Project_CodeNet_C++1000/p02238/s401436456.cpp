#include <stdio.h>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;

ll d[100], f[100], now, cnt;
char flag[100];
vector<int> vec[100];

int dfs(int n) {
  if(flag[n]) return 0;
  flag[n] = 1;
  cnt++;
  d[n] = cnt;
  vector<int>::iterator it;
  for(it = vec[n].begin(); it != vec[n].end(); ++it) {
    if(!flag[*it]) dfs(*it);
  }
  ++cnt;
  f[n] = cnt;
  return 0;
}

int main(void) {
  ll n;
  scanf("%d", &n);
  now = 0, cnt = 0;
  rep(i, n) flag[i] = 0;
  rep(i, n) {
    int u, k;
    scanf("%d%d", &u, &k);
    u--;
    rep(j, k) {
      int v;
      scanf("%d", &v);
      v--;
      vec[u].push_back(v);
    }
    sort(vec[u].begin(), vec[u].end());
  }
  now = 0;
  while( 1 ) {
    dfs(now);
    int s = 1, i;
    for(i = 0; i < n; ++i) if(!flag[i]){
      s = 0;
      break;
    }
    if(s) break;
    else now = i;
    //rep(j, n) printf("%d ", (int)flag[j]);
    //printf("%d\n", i);
    //return 0;
  }
  rep(i, n) printf("%d %lld %lld\n", i + 1, d[i], f[i]);
  return 0;
}
