#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> lun;

void dfs(ll num)
{
  if (num > 3234566667) return;

  lun.emplace_back(num);

  ll d = num % 10;
  if (d > 0) dfs(num * 10 + d-1);
  dfs(num * 10 + d);
  if (d < 9) dfs(num * 10 + d+1);
}

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= 9; ++i) dfs(i);
  sort(lun.begin(), lun.end());

  cout << lun[n-1] << '\n';

  return (0);
}
