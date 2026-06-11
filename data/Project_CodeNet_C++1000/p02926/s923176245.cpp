#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
//typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

const ll mod = 1e9 + 7;


int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  vector<pair<ll, ll>> ps(N);
  REP(i, N) {
    ll x, y; cin >> x >> y;
    ps[i] = make_pair(x, y);
  }

  sort(ps.begin(), ps.end(), [](auto const& lhs, auto const& rhs) {
    double d1 = std::atan2(lhs.second, lhs.first), d2 = std::atan2(rhs.second, rhs.first);
    return d1 < d2;
  });

  ll ans = 0;
  REP(i, N) {
    ll x = 0, y = 0;
    REP(j, N) {
      x += ps[(i+j)%N].first;
      y += ps[(i+j)%N].second;
      ans = max(ans, x * x + y * y);
    }
  }

  std::cout << std::setprecision(30);
  std::cout << std::sqrt(ans) << std::endl;

  return 0;
}
