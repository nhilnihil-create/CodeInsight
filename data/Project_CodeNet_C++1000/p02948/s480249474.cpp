#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T, typename C> void printset(const multiset<T, C> &s) {
  for (auto &t : s) {
    cout << t << " ";
  }
  cout << endl;
}

int main() {
  ll N, M;
  vector<vector<ll>> jobs(100001);
  cin >> N >> M;

  for (ll i = 0; i < N; i++) {
    ll a, b;
    cin >> a >> b;
    jobs[a].push_back(b);
  }

  ll sum = 0;
  multiset<ll, greater<ll>> board;

  for (ll i = 1; i <= M; i++) {
    board.insert(jobs[i].begin(), jobs[i].end());

    if (board.size() > 0) {
      auto it = board.begin();
      sum += *it;
      board.erase(it);
    }
  }

  cout << sum << endl;
}
