#include <bits/stdc++.h>
using namespace std;

const int INF = 100100100;
const int MOD = (int)1e9 + 7;
typedef long long ll;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)


int main() {
  double a,b;
  cin >> a >> b;
  if (int((a+b)/2) == (a+b)/2)cout << int((a+b)/2) << endl;
  else cout << "IMPOSSIBLE" << endl;
}