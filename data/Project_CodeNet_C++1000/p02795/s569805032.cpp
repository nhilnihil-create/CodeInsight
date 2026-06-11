#include <bits/stdc++.h>
using namespace std;
#define REP(i, n)  for (int i = 0; i < (int) (n); i++)
#define REP1(i, n) for (int i = 1; i <= (int) (n); i++)
#define all(x)     (x).begin(), (x).end()
#define SZ(x)      ((int) (x).size())
using ll = long long;
const ll mod  = 1e9 + 7;
const int INF = 2e9;
using pint = pair <int, int>;

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  int m = max(h, w);
  cout << (n + m - 1) / m << endl;
  return 0;
}
