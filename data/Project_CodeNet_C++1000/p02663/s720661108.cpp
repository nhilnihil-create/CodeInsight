#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  int h, m;
  cin >> h >> m;
  int now = h * 60 + m;
  cin >> h >> m;
  int next = h * 60 + m;
  int k;
  cin >> k;
  cout << next - now - k << endl;
}