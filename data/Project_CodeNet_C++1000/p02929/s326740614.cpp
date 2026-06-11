/*
-----------------------------------------------------------------------------
Author :            ---------------------------------------------------------
    UTKARSH SAXENA  ---------------------------------------------------------
    GOOGLE          ---------------------------------------------------------
-----------------------------------------------------------------------------
*/
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define fre freopen("0.in", "r", stdin), freopen("0.out", "w", stdout)
#define abs(x) ((x) > 0 ? (x) : -(x))
#define MOD 1000000007
#define LL signed long long int
#define ps(x) push_back(x)
#define scan(x) scanf("%d", &x)
#define print(x) printf("%d\n", x)
#define scanll(x) scanf("%lld", &x)
#define printll(x) printf("%lld\n", x)
#define boost ios_base::sync_with_stdio(0)
// vector<int> g[2*100000+5];int par[2*100000+5];
int main() {
  // fre;
  int N;
  string S;
  cin >> N >> S;
  int R = 0;
  LL ans = 1;
  for (int i = 2 * N - 1; i >= 0; i--) {
    char deb = 'R';
    if (S[i] == 'B') {
      if (R % 2 == 1) {
        // place L.
        deb = 'L';
        ans *= R;
        R--;
      } else {
        R++;
      }
    } else {
      if (R % 2 == 1) {
        ++R;
      } else {
        // place L.
        deb = 'L';
        ans *= R;
        --R;
      }
    }
    // cout << i << ' ' << deb << endl;
    if (R < 0) {
      cout << 0;
      return 0;
    }
    ans %= MOD;
  }
  if (R != 0) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= N; ++i) {
    ans = ans * i % MOD;
  }
  cout << ans;
}
