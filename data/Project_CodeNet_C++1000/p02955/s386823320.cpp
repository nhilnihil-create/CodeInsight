#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int n, k;
vector<int> a;
int sum = 0;
int ans = 0;

bool check(int v) {
  vector<int> b(n);
  REP(i, n) b[i] = a[i] % v;
  sort(ALL(b));
  vector<ll> b_sum(n + 1);
  b_sum[0] = 0;
  REP(i, n) b_sum[i + 1] = b_sum[i] + b[i];
  REP(i, n + 1) {
    ll cnt1 = b_sum[i];
    ll cnt2 = 1ll * v * (n - i) - (b_sum[n] - b_sum[i]);
    if (max(cnt1, cnt2) <= k) return true;
  }
  return false;
}

int main() {
  cin >> n >> k;
  a.resize(n);
  REP(i, n) cin >> a[i];
  REP(i, n) sum += a[i];
  for (int i = 1; i * i <= sum; ++i) {
    if (sum % i == 0) {
      if (check(i)) ans = max(ans, i);
      if (check(sum / i)) ans = max(ans, sum / i);
    }
  }
  cout << ans << endl;
  return 0;
}