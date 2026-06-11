#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cmath>

using namespace std;
typedef long long lint;
typedef vector<int> vi;
typedef pair<int,int> pii;

typedef vector<lint> vl;
typedef pair<lint,lint> pll;

int last(vi a){
  int n = a.size();
  //for (int i=0; i<n; ++i) a[i] = rand()%3;
  //vi oa = a;
  for (int len = n-1; len>=1; --len){
    vi b(n);
    for (int i = 0; i<len; ++i){
      b[i] = abs(a[i]-a[i+1]);
    }
    a = b;
  }
  return a[0];
}


int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n; cin>>n>>m;
    vector<string> mp(n);
    for (auto &s : mp) cin>>s;

    vector<vi> dp(n, vi(m, m*n+10));

    deque<pii> bfs;
    bfs.push_back({0, 0});
    if (mp[0][0] == '#') dp[0][0] = 1;
    else dp[0][0] = 0;

    auto push = [&](int i, int j, int l, bool front){
      if (l < dp[i][j]){
        dp[i][j] = l;
        if (front)bfs.push_front({i,j});
        else bfs.push_back({i,j});
      }
    };

    vector<vi> dir({{0,1}, {1,0}});

    while(!bfs.empty()){
      pii p = bfs.front(); bfs.pop_front();
      int l = dp[p.first][p.second];
      for (vi di : dir){
        int nx = p.first+di[0];
        int ny = p.second + di[1];
        if (nx < n && ny < m){
          int nl = l;
          if (mp[p.first][p.second] == '.' && mp[nx][ny] == '#') nl++;
          push(nx, ny, nl, nl==l);
        }
      }
    }
    cout<<dp[n-1][m-1];

    return 0;
}
