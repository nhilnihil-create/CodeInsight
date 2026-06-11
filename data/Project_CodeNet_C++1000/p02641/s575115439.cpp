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
  int x, n;
  cin >> x >> n;
  vector <int> p(n);
  rep(i, n) cin >> p[i];
  vector <int> elim_100(102);
  repr(i, 1, 102) {
    elim_100[i] = i;
    rep(j, n) {
      // std::cout << p[j] << '\n';
      if (i == p[j]) {
        elim_100[i] = 1000;
      }
    }
    // std::cout << elim_100[i] << '\n';
  }
  int dif_prv = INF;
  int dif     = 102;
  ll  ans     = 0;
  repr(i, 0, 102) {
    dif = abs(elim_100[i] - x);
    // std::cout << dif << '\n';
    if (dif_prv > dif) {
      ans     = i;
      dif_prv = dif;
    }
  }
  cout << ans << endl;

  return 0;
}
