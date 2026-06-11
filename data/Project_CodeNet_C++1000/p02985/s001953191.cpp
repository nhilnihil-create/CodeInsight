#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <bitset>
#include <set>
#include <deque>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define all(i,n) (i),(i+n)

int dx4[4]={1,0,-1,0};
int dy4[4]={0,-1,0,1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};

typedef pair<int, int> P;
typedef pair<string, int> SP;
typedef long long ll;
typedef pair<ll, ll> PLL;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;

// --------------------------------------
int n, k;
int p;

ll dfs(vector<vector<int>>& g, int now, int from) {
  int can_use_color_num;
  if(from == -1) can_use_color_num = k - 1;
  else can_use_color_num = k - 2;

  ll cc = 1;
  if(k < (int)g[now].size()) {
    return 0;
  } else {
    for(auto e: g[now]) {
      if(e == from) continue;
      cc *= can_use_color_num;
      can_use_color_num--;
      cc %= mod;
    }

    for(auto e: g[now]) {
      if(e == from) continue;
      cc *= dfs(g, e, now);
      cc %= mod;
    }
    return cc;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> k;

  vector<vector<int>> g(n);
  REP(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int ma = 0;
  REP(i, n) if(ma < g[i].size()) p = i, ma = g[i].size();

  ll ans = (k * dfs(g, p, -1)) % mod;
  cout << ans << endl;
}
