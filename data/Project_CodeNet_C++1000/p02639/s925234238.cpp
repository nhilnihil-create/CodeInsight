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
  std::vector <int> x(5);
  rep(i, 5) cin >> x[i];
  ll ans = 0;
  rep(i, 5) {
    if (x[i] == 0) {
      ans = i;
      break;
    }
  }
  cout << ans + 1 << endl;

  return 0;
}
