#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

ll mod = 1000000007;
int n, k;
vector<vector<int>> v;
ll ans;

void dfs(int pre, int crt)
{
  rep(i, v[crt].size() - 1)
    ans = ans * (k - i - 2) % mod;
  for (int i : v[crt])
    if (i != pre)
      dfs(crt, i);
}

int main()
{
  cin >> n >> k;
  v.resize(n);
  rep(i, n - 1)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  ans = k;
  rep(i, v[0].size())
    ans = ans * (k - i - 1) % mod;
  for (int i : v[0])
    dfs(0, i);
  cout << ans << endl;
  return 0;
}