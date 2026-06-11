#include <bits/stdc++.h>
using namespace std;

const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)


int main() {
  int n,d;
  cin >> n >> d;
  d = 2*d + 1;
  int ans = n/d;
  if (n%d!=0) ans++;
  cout << ans << endl;
}