#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> a(n+1), b(m+1);

  a.at(0) = 0;
  for (long long i = 1; i <= n; ++i) {
    long long ai;
    cin >> ai;
    a.at(i) = a.at(i-1) + ai;
  }
  b.at(0) = 0;
  for (long long i = 1; i <= m; ++i) {
    long long bi;
    cin >> bi;
    b.at(i) = b.at(i-1) + bi;
  }
  long long ans = 0;
  long long j = m;
  for (long long i = 0; i <= n; ++i) {
    while (b.at(j) + a.at(i) > k) {
      --j;
      if (j < 0) break;
    }
    if (j >= 0 && i + j > ans) ans = i + j;
    if (j < 0) break;
  }
  cout << ans << endl;
  return 0;
}
