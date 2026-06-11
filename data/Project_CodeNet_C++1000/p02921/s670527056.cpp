#include <bits/stdc++.h>
using namespace std;

const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)


int main() {
  string a,b;
  cin >> a >> b;
  int ans = 0;
  REP(i,3) ans += a[i]==b[i]; 
  cout << ans << endl;
}