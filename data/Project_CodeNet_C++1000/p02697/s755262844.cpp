#include <bits/stdc++.h>
using namespace std;

#define name ""
#define ini freopen(name".inp","r",stdin); freopen(name".out","w",stdout)
#define foe(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define long long long 
#define db double 
#define pii pair <int, int>
#define pll pair <long, long>
#define all(c) c.begin(), c.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const int INF = 1e9+7;
const int MOD = 1e9+7;
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};

int main()
{
  fastio;
  int n, m; cin >> n >> m;
  vector <pii> res;
  int x = (n + 1) / 2;
  auto F = [&](int l, int r){
    while (l < r){
      res.push_back(pii(l, r));
      l++; r--;
    }  
  };
  F(1, x);
  if (n & 1) F(x + 1, n);
  else F(x + 2, n);
  for (int i = 0; i < m; i++) cout << res[i].first << ' ' << res[i].second << '\n';
  return 0;
}