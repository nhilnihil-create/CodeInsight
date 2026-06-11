#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <map>

#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int INF = pow(2,29);
const int MOD = 1000000007;

int main() {
  int N; cin >> N;
  int x[N], y[N]; rep(i,N) cin >> x[i] >> y[i];

  int result = N;
  rep(i, N) for(int j=i+1; j<=N; j++) {
    int p = x[i]-x[j], q = y[i]-y[j];
    int tmp = N;
    rep(k, N) rep(l, N) {
      if (x[k]-x[l]==p && y[k]-y[l]==q) tmp--;
    }
    result = min(result, tmp);
  }
  cout << result << endl;
  return 0;
}