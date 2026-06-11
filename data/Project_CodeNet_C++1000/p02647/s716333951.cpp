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

ll A[200050];
ll B[200050];

int main() {
  // std::cout << std::fixed << std::setprecision(10);

  ll N, K;
  scanf("%lld %lld", &N, &K);

  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);
    A[i] = v;
  }

  if (K > 600) {
    fill_n(B, 200005, N);
  } else {
    for (ll i = 0; i < K; i++) {
      fill_n(B, N, 0);
      for (ll i = 0; i < N; i++) {
        ll v = A[i];

        ll l = max(i - v, 0LL);
        ll r = min(i + v, N - 1LL);

        B[l] += 1;
        if (r + 1 < N) {
          B[r + 1] -= 1;
        }
      }
      for (int i = 1; i < N; i++) {
        B[i] += B[i - 1];
      }
      memcpy(A, B, sizeof(A));
    }
  }

  cout << B[0];
  for (ll i = 1; i < N; i++) {
    cout << " " << B[i];
  }
}
