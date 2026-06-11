#include <bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <typename Q_type>
using smaller_queue = priority_queue<Q_type, vector<Q_type>, greater<Q_type>>;

const int MOD_TYPE = 1;
const ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);
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
#define possible(n) cout << ((n) ? "possible" : "impossible") << endl
#define Yay(n) cout << ((n) ? "Yay!" : ":(") << endl
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << endl;

vector<int> Dx = {0, 0, -1, 1, -1, 1, -1, 1, 0};
vector<int> Dy = {1, -1, 0, 0, -1, -1, 1, 1, 0};

class BellmanFord
{
public:
  static const ll MAX_V = 1010 * 1010;

  struct edge
  {
    ll from, to;
    ll cost;
  };

  ll V;
  vector<edge> E;
  ll d[MAX_V];

  BellmanFord(ll V_num) : V(V_num) {}

  void calc(ll s)
  {
    fill(d, d + V + 1, LINF);
    d[s] = 0;
    bool update;
    while (1)
    {
      update = false;
      for (auto e : E)
      {
        if (d[e.from] != LINF && d[e.to] > d[e.from] + e.cost)
        {
          d[e.to] = d[e.from] + e.cost;
          update = true;
        }
      }
      if (!update)
        return;
    }
  }

  bool negative[MAX_V];

  bool calc_and_find_negative_loop(ll s, ll g)
  {
    fill(d, d + V + 1, LINF);
    fill(negative, negative + V + 1, false);
    d[s] = 0;

    rep(i, V)
    {
      bool update = false;
      for (auto e : E)
      {
        if (d[e.from] != LINF && d[e.to] > d[e.from] + e.cost)
        {
          d[e.to] = d[e.from] + e.cost;
          update = true;
          if (i == V - 1)
            negative[e.from] = negative[e.to] = true;
        }
      }
      if (!update)
        return false;
    }
    return negative[g];
  }

  bool find_any_negative_loop()
  {
    ll d_[MAX_V];
    rep(i, V) for (auto e : E)
    {
      if (d_[e.to] > d_[e.from] + e.cost)
      {
        d_[e.to] = d_[e.from] + e.cost;
        if (i == V - 1)
          return true;
      }
    }
    return false;
  }
};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll v, e, r;
  cin >> v >> e >> r;
  BellmanFord bf(v);
  rep(i, e)
  {
    ll s, t, d;
    cin >> s >> t >> d;
    bf.E.push_back({s, t, d});
  }
  bf.calc_and_find_negative_loop(r, 0);
  bool neg = false;
  rep(i, v) neg |= bf.negative[i];
  if (neg)
  {
    cout << "NEGATIVE CYCLE\n";
  }
  else
  {
    rep(i, v)
    {
      if (bf.d[i] == LINF)
        cout << "INF\n";
      else
        cout << bf.d[i] << endl;
    }
  }
  return 0;
}

