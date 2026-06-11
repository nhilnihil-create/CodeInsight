#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  ll N, K;
  cin >> N >> K;
  vector<int> a(N + 1);
  vector<int> ov(2010);
  REP(i, N) {
    cin >> a[i + 1];
    ov[a[i + 1]]++;
  }
  REP(i, 2005) { ov[i + 1] += ov[i]; }
  ll tenti = 0;
  for (int i = 1; i <= N; i++) {
    ll tmp = 0;
    tmp = (K * (K - 1)) / 2 % MOD;
    tmp *= ov[a[i] - 1];
    tmp %= MOD;
    tenti += tmp;
    tenti %= MOD;
    ll k = 0;
    for (int j = i + 1; j <= N; j++) {
      if (a[i] > a[j]) k++;
    }
    tenti += (k * K) % MOD;
    tenti %= MOD;
  }
  cout << tenti << endl;
}