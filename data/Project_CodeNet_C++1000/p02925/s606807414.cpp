#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = (int)(n); i > 0; i--)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define INF 2e9
#define ALL(v) (v).begin(), (v).end()
template <typename Iter> std::string join(Iter begin, Iter end, std::string const& separator){ std::ostringstream result; if (begin != end){ result << *begin++; }; while (begin != end){ result << separator << *begin++; }; return result.str(); }
using namespace std;
typedef long long ll;
ll match_id(ll p1, ll p2, ll N) {
  ll p3 = min(p1, p2);
  ll p4 = max(p1, p2);
  return p3 * N + p4;
}
pair<ll, ll> match_pair(ll id, ll N) {
  ll p1 = id / N;
  ll p2 = id % N;
  ll p3 = min(p1, p2);
  ll p4 = max(p1, p2);
  return make_pair(p3, p4);
}
void solve() {
  ll N; cin >> N;
  vector<vector<ll>> A(N, vector<ll>(N-1));
  REP(i, N) {
    REP(j, N-1) {
      ll a;
      cin >> a;
      a--;
      A[i][j] = a;
    }
  }
  vector<vector<ll>> next_match(N * N + N, vector<ll>(2, -1));
  vector<ll> depend(N * N + N, 0);
  REP(i, N) {
    REP(j, N-2)  {
      ll p1 = i;
      ll p2 = A[i][j];
      ll p2next = A[i][j+1];
      ll current = match_id(p1, p2, N);
      ll next = match_id(p1, p2next, N);
      if(next_match[current][0] == -1) {
        next_match[current][0] = next;
      } else {
        next_match[current][1] = next;
      }
      depend[next]++;
    }
  }
  unordered_set<ll> avail;
  REP(i, N) {
    ll p1 = i;
    ll p2 = A[i][0];
    auto match = match_id(p1, p2, N);
    if(depend[match] == 0) {
      avail.insert(match);
    }
  }
  ll n_match = 0;
  REP(d, N * (N - 1) / 2) {
    if(avail.size() == 0) {
      cout << -1 << endl;
      return;
    }
    unordered_set<ll> next_avail;
    for(auto m: avail) {
      n_match++;
      for(auto next: next_match[m]) {
        if(next == -1) continue;
        depend[next]--;
        if(depend[next] == 0) next_avail.insert(next);
      }
    }
    avail = next_avail;
    if(n_match == N * (N - 1) / 2) {
      cout << d + 1 << endl;
      return;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
