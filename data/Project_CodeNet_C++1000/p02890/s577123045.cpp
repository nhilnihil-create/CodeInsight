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

int main() {
  int n;
  cin >> n;
  int a[n];
  REP(i, n) cin >> a[i];
  vector<int> cnt(n + 1);
  REP(i, n) cnt[a[i]]++;
  vector<int> cnt2(n + 1);
  REP1(i, n) cnt2[cnt[i]]++;
  vector<ll> sum1(n + 1), sum2(n + 1);
  REP1(i, n) {
    sum1[i] = sum1[i - 1] + i * cnt2[i];
    sum2[i] = sum2[i - 1] + cnt2[i];
  }
  REP1(k, n) {
    int ok = 0, ng = n + 1;
    while (1 < abs(ok - ng)) {
      int x = (ok + ng) / 2;
      ll sum = sum1[x] + x * (sum2[n] - sum2[x]);
      if (k <= sum / x) {
        ok = x;
      } else {
        ng = x;
      }
    }
    cout << ok << endl;
  }
  return 0;
}