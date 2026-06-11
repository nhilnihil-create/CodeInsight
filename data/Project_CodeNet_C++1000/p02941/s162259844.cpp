#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define rep(X, S, E) for (int(X) = (S); (X) < (E); ++(X))
#define rrep(X, S, E) for (int(X) = (E)-1; (X) >= (S); --(X))
#define arep(X, Y) for (auto(X) : Y)
#define all(X) (X).begin(), (X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define print(x) cout << x << endl
#define printDouble(x) cout << fixed << setprecision(13) << x << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

using decendingQueue = priority_queue<pll, vector<pll>>; //降順

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll INT_INF = 1e9;
const ll LL_INF = 1e18;
const int mod = 1000000007;

void solve(long long N, std::vector<long long> A, std::vector<long long> B) {
  decendingQueue pq;
  rep(i, 0, N) {
    if (A[i] != B[i]) {
      pq.push(mp(B[i], i));
    }
  }

  ll cnt = 0;
  while (!pq.empty()) {
    auto i = pq.top().sc;
    pq.pop();

    ll s = B[i - 1 < 0 ? N - 1 : i - 1] + B[(i + 1) % N];
    ll t = (B[i] - A[i]) / s;
    B[i] -= s * t;

    cnt += t;

    if (t == 0) {
      print("-1");
      return;
    }

    if (B[i] > A[i]) {
      pq.push(mp(B[i], i));
    }
  }
  print(cnt);
}

int main() {
  long long N;
  scanf("%lld", &N);
  std::vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }
  std::vector<long long> B(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &B[i]);
  }
  solve(N, std::move(A), std::move(B));
  return 0;
}
