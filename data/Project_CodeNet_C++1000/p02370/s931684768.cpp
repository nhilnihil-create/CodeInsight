#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
//グラフDFS
void dfs(ll x, vector<vector<ll>> &g, vector<bool> &see, vector<pair<ll, ll>> &ans, ll &cnt)
{
  //点xに対する処理
  see[x] = 1;
  for (auto p : g[x])
  {
    if (see[p])
      continue;
    //進む辺に対する処理（これは木構造でオイラーツアーするために使う）
    dfs(p, g, see, ans, cnt);
    //戻る辺に対する処理
  }
  ans[x].first = cnt;
  cnt++;
}
int main()
{
ll n, m;
cin >> n >> m;
vector<vector<ll>> g(n);
rep(i, m)
{
  ll a, b;
  cin >> a >> b;
  g[a].push_back(b);
}
ll cnt = 1;
vector<bool> see(n);
vector<pair<ll, ll>> ans(n);
rep(i, n) ans[i].second = i;
rep(i, n)
{
  if (!see[i])
    dfs(i, g, see, ans, cnt);
}
sort(ans.begin(),ans.end());
reverse(ans.begin(),ans.end());
rep(i,n)cout << ans[i].second << endl;
return 0;
}
