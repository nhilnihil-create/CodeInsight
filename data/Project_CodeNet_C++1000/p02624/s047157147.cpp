#include <iostream>
using namespace std;

long long f[10000001];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int j = i;
    while (j <= n) {
      f[j]++;
      j += i;
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= n; ++i) {
    ans += i * f[i];
  }
  cout << ans << endl;
  return 0;
}
