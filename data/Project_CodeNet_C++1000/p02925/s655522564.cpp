#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
  ll n;
  cin >> n;
 
  ll aij;
  vector<queue<ll>> a(n);
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n - 1; j++) {
      cin >> aij;
      a[i].push(aij - 1);
    }
  }

  ll games_max = n * (n - 1) / 2;
  ll games = 0;
  ll days = 0;

  queue<ll> q, q_next;
  for (ll i = 0; i < n; i++) q_next.push(i);

  while (!q_next.empty()) {
    // cout << "day" << endl;

    vector<bool> done(n, false);
    q.swap(q_next);
    queue<ll>().swap(q_next);

    while (!q.empty()) {
      ll i = q.front(); q.pop();
      ll j = a[i].front();

      if (done[i] || a[i].empty()) continue;
      if (done[j] || a[j].empty()) continue;

      if (a[j].front() == i) {
        // cout << i << " " << j << endl;

        done[i] = true;
        done[j] = true;

        a[i].pop();
        a[j].pop();

        if (!a[i].empty()) q_next.push(i);
        if (!a[j].empty()) q_next.push(j);
        games++;
      }
    }
    days++;
  }
 
  if (games == games_max) {
    cout << days << endl;
  } else {
    cout << -1 << endl;
  }
}
