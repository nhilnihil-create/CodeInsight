#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P  = pair <int, int>;

#define rep(i, n)     for (int i = 0; i < (int) (n); i++)
#define repr(i, a, b) for (int i = a; i < b; i++)
#define each(i, mp)   for (auto &i : mp)

const int INF = 1001001001;

int main()
{
  int n, k;
  cin >> n >> k;
  vector <int> p(n);
  rep(i, n) cin >> p[i];
  sort(p.begin(), p.end());
  ll ans = 0;
  rep(i, k) {
    ans += p[i];
  }
  cout << ans << endl;

  return 0;
}
