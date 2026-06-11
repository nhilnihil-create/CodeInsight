#include <stdio.h>
#include <vector>
#include <set>
#include <utility>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, j, k, n, m, u, v, a;
  scanf("%lld%lld", &n, &m);
  vector<ll> vec[n];
  ll d[n][3];
  for(i = 0; i < m; ++i) {
    scanf("%lld%lld", &u, &v);
    vec[--u].push_back(--v);
  }
  set< pair<ll, pair<ll, ll> > > s;
  pair<ll, ll> now;
  scanf("%lld%lld", &u, &v), --u, --v;
  for(i = 0; i < n; ++i) for(j = 0; j < 3; ++j) d[i][j] = 1e9;
  d[u][0] = 0;
  for(i = 0; i < n; ++i) for(j = 0; j < 3; ++j) 
    s.insert(make_pair(d[i][j], make_pair(i, j)));
  while(s.size()) {
    a = (*s.begin()).first, now = (*s.begin()).second, s.erase(s.begin());
    now.second++;
    now.second %= 3;
    if(!now.second) a++;
    for(i = 0; i < vec[now.first].size(); ++i) {
      j = vec[now.first][i];
      if(d[j][now.second] > a) {
        s.erase(make_pair(d[j][now.second], make_pair(j, now.second)));
        d[j][now.second] = a;
        s.insert(make_pair(a, make_pair(j, now.second)));
      }
    }
  }
  printf("%lld", d[v][0] == 1e9 ? -1 : d[v][0]);
  return 0;
}