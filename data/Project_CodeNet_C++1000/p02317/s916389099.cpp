#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))
#define ALL(v) (v).begin(), (v).end()
#define LENGTHOF(x) (sizeof(x) / sizeof(*(x)))
#define AFILL(a, b) fill((int*)a, (int*)(a + LENGTHOF(a)), b)
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 1 << 30
#define EPS 1e-10
#define MAX_N 100000

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

int dp[MAX_N+1];
int n, a[MAX_N];

int main(){
  scanf("%d", &n);
  rep(i, n) scanf("%d", a+i);

  fill(dp, dp + n, INF);
  rep(i, n){
    *lower_bound(dp, dp + n, a[i]) = a[i];
  }
  printf("%d\n", lower_bound(dp, dp + n, INF) - dp);

  return 0;
}