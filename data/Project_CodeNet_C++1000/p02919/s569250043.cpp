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

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; std::cin >> N;
  vector<ll> P(N); REP(i, N) std::cin >> P[i];
  vector<pair<ll, ll>> value_idx(N);
  REP(i, N) value_idx[i] = std::make_pair(P[i], (ll)i);
  std::sort(ALL(value_idx));

  multiset<int> mset = {-1, -1, N, N};
  ll ans = 0;
  for (int i = N-1; i >= 0; i--) {
    ll value, idx; tie(value, idx) = value_idx[i];
    auto it = mset.insert(idx);
    it--; ll l1 = *it;
    it--; ll l2 = *it;
    it = mset.find(idx);
    it++; ll r1 = *it;
    it++; ll r2 = *it;
    ans += ((l1 - l2) * (r1 - idx) + (r2 - r1) * (idx - l1)) * value;
  }
  std::cout << ans << endl;
  return 0;
}
