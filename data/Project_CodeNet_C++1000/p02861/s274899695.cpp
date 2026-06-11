#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n;
  cin >> n;
  vector<P> p(n);
  rep(i, n)
  {
    int x, y;
    cin >> x >> y;
    p[i] = make_pair(x, y);
  }
  vector<int> a(n);
  rep(i, n) a[i] = i;
  sort(a.begin(), a.end());
  double sum = 0.0;
  int cnt = 0;
  do
  {
    rep(i, n - 1)
    {
      double x = p[a[i]].first - p[a[i + 1]].first;
      double y = p[a[i]].second - p[a[i + 1]].second;
      sum += sqrt(x * x + y * y);
    }
    cnt++;
  } while (next_permutation(a.begin(), a.end()));
  double ave = sum / cnt;
  cout << fixed << setprecision(10);
  cout << ave << endl;
  return 0;
}