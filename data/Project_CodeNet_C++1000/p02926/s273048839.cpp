#include <bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename Q_temp>
using smaller_queue = priority_queue<Q_temp, vector<Q_temp>, greater<Q_temp>>;

const ll MOD = (ll)(1e9 + 7);
const int INF = (int)1e9;
const ll LINF = (ll)4e18;
const double PI = acos(-1.0);

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << endl;

vector<int> Dx = {0, 0, -1, 1, -1, 1, -1, 1, 0};
vector<int> Dy = {1, -1, 0, 0, -1, -1, 1, 1, 0};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(50) << setiosflags(ios::fixed);

  int n;
  cin >> n;

  struct vec
  {
    ld x, y;
  };

  vector<vec> v;
  rep(i, n)
  {
    ld xi, yi;
    cin >> xi >> yi;
    if (xi == 0.0 && yi == 0.0)
      n--, i--;
    else
      v.push_back({xi, yi});
  }

  auto comp = [](vec &v1, vec &v2) {
    return atan2(v1.y, v1.x) < atan2(v2.y, v2.x);
  };

  sort(all(v), comp);
  rep(i, n) cerr << v[i].x << " " << v[i].y << endl;
  cerr << endl;

  rep(i, n) v.push_back(v[i]);
  ld Max = 0.0;
  for (int choose = 1; choose <= n; ++choose)
  {
    rep(start, n)
    {
      ld x_sum = 0.0, y_sum = 0.0;
      for (int i = start; i < start + choose; ++i)
      {
        x_sum += v[i].x;
        y_sum += v[i].y;
      }
      Max = max(Max, sqrt(x_sum * x_sum + y_sum * y_sum));
    }
  }
  cout << Max << endl;
  return 0;
}
