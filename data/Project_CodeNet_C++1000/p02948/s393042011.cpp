#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(n);
  rep(i, n)
    cin >> a[i].first >> a[i].second;
  sort(a.begin(), a.end(), greater<pair<int, int>>());
  ll ans = 0;
  priority_queue<int> q;
  rep(i, m + 1)
  {
    while (a.back().first <= i)
    {
      q.push(a.back().second);
      a.erase(a.end() - 1);
    }
    if (!q.empty())
    {
      ans += q.top();
      q.pop();
    }
  }
  cout << ans << endl;
  return 0;
}