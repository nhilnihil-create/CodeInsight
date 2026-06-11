#include <bits/stdc++.h>

using namespace std;

#define FOR(i,s,e) for((i)=(s);(i)<(int)(e);(i)++)
#define REP(i,e) FOR(i,0,e)

#define all(o) (o).begin(), (o).end()
#define psb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))

typedef long long ll;
typedef pair<int, int> PII;

const double EPS = 1e-10;

const int N = 1000*100;
const int INF = 1e+9;
int n;
int a[N+1];
int dp[N+1];

int main() {
  int i;
  scanf("%d ", &n);
  REP(i,n) scanf("%d ", a+i);
  fill(dp, dp+n, INF);
  REP(i,n) *lower_bound(dp, dp+n, a[i]) = a[i];
  printf("%d\n", (int)(lower_bound(dp, dp+n, INF) - dp));
  return 0;
}