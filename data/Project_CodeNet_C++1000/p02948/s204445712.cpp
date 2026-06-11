#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n) - 1; 0 <= i; --i)
#define rep(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
using ll = long long;
using arr = vector<ll>;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;
constexpr int MAX = 2020;

int n, m;
int main()
{
  cin >> n >> m;
  vector<pair<ll, ll>> task;
  priority_queue<ll> pq;
  REP(i, n) {
    ll a, b;
    cin >> a >> b;
    task.emplace_back(a, b);
  }
  sort(task.begin(), task.end());

  int j = 0;
  ll ans = 0;
  rep(i, m) {
    while(j < n && task[j].first == i) 
      pq.emplace(task[j++].second);
    if (pq.empty()) continue;
    ans += pq.top();
    pq.pop();
  }
  cout << ans;

  return 0;
}