#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

vll r[200005];
ll points[200005];

mll finished;

void calc(ll index, ll plus) {
  if (finished[index]) {
    return;
  }
  points[index] += plus;

  vll list = r[index];

  finished[index] = 1;

  for (ll i = 0; i < list.size(); i++) {
    ll next_index = list[i];

    calc(next_index, points[index]);
  }
}

int main() {
  ll N, Q;
  scanf("%lld %lld", &N, &Q);

  for (ll i = 0; i < N - 1; i++) {
    ll a, b;
    scanf("%lld %lld", &a, &b);

    r[a].emplace_back(b);
    r[b].emplace_back(a);
  }

  for (ll i = 0; i < Q; i++) {
    ll p, x;
    scanf("%lld %lld", &p, &x);

    points[p] += x;
  }

  calc(1, 0);

  cout << points[1];
  for (ll i = 2; i <= N; i++) {
    cout << " " << points[i];
  }
}
