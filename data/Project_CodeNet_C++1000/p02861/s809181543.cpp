#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cout << fixed << setprecision(10);
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<pair<int,int>> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;

  sort(p.begin(), p.end());
  long double sum = 0, cnt = 0;

  do {
    for (int i = 0; i < n-1; ++i) sum += sqrt(pow(p[i].first - p[i+1].first, 2) + pow(p[i].second - p[i+1].second, 2));

    ++cnt;
  } while (next_permutation(p.begin(), p.end()));

  cout << sum / cnt << endl;

  return (0);
}
