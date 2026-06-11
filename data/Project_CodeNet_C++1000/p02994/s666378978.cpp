#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int N, L;
  cin >> N >> L;
  int s = 0;
  REP(i, N) {
    s += L + i;
  }
  pair<int, int> p = make_pair(INF, INF);
  REP(i, N) {
    int tmp = 0;
    REP(j, N) {
      if (i == j) {
        continue;
      }
      tmp += L + j;
    }
    if (abs(s - tmp) < p.first) {
      p.first = abs(s - tmp);
      p.second = tmp;
    }
  }
  cout << p.second << endl;

  return 0;
}