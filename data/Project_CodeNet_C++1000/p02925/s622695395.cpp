#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N;
  cin >> N;
  vector<queue<ll>> A(N);
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < N - 1; ++j) {
      ll a;
      cin >> a;
      A.at(i).push(a - 1);
    }
  }
  ll ans = 0;
  bool change = true;
  queue<ll> pos;
  for (ll i = 0; i < N; ++i) {
    pos.push(i);
  }
  while (change) {
    change = false;
    vector<ll> already(N, false);
    queue<ll> next_pos;
    while (!pos.empty()) {
      ll i = pos.front();
      pos.pop();
      if (already.at(i) || A.at(i).empty()) {
        continue;
      }
      ll opp = A.at(i).front();
      if (already.at(opp) || A.at(opp).empty()) {
        continue;
      }
      if (A.at(opp).front() == i) {
        A.at(i).pop();
        A.at(opp).pop();
        change = true;
        already.at(i) = true;
        already.at(opp) = true;
        next_pos.push(i);
        next_pos.push(opp);
      }
    }
    pos = next_pos;
    if (change) {
      ans += 1;
    }
  }
  for (ll i = 0; i < N; ++i) {
    if (!A.at(i).empty()) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
}
