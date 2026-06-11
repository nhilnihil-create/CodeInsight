#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { std::cout << #a << " = " << a << "\n"; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }
template<class T, class V> istream& operator>> (istream& ist, pair<T, V>& p) { return ist >> p.first >> p.second; }
template<class T> ostream& operator<< (ostream& ost, pair<T, T>& p) { return ost << p.first << ", " << p.second; }
template<class T> istream& operator>> (istream& ist, vector<T>& vs) { for(auto& e: vs) ist >> e; return ist; }

typedef long long ll;
int const inf = INT_MAX / 2;

int main() {
  int N; cin >> N;
  vector<int> x(N), y(N);
  rep(i, N) cin >> x[i] >> y[i];
  map<pair<int, int>, int> mp;
  rep(i, N) {
    mp.emplace(make_pair(x[i], y[i]), i);
  }
  set<pair<int, int>> pqs;
  rep(i, N) REP(j, i + 1, N) {
    auto p = x[i] - x[j], q = y[i] - y[j];
    pqs.emplace(p, q);
    pqs.emplace(-p, -q);
  }
  int ans = inf;
  for (auto pq: pqs) {
    auto p = pq.first, q = pq.second;
    int cnt = 0;
    rep(i, N) {
      cnt += !mp.count(make_pair(x[i] - p, y[i] - q));
    }
    ans = min(ans, cnt);
  }
  if (ans == inf) {
    cout << "1\n";
  } else {
    cout << ans << "\n";
  }
}
