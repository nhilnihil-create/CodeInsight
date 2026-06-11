#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int main(void) {
  int n, m;
  cin >> n >> m;
  vector<ll> way(n + 1);
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    way[a] = -1;
  }
  way[0] = 1LL;
  for (int i = 1; i <= n; i++) {
    if (way[i] >= 0 && way[i - 1] >= 0) {
      way[i] = (way[i] + way[i - 1]) % MOD;
    }
    if (i > 1 && way[i] >= 0 && way[i - 2] >= 0) {
      way[i] = (way[i] + way[i - 2]) % MOD;
    }
  }
  cout << way[n] << endl;
  return 0;
}