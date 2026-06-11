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
#define MAX_N 100
#define MAX_W 10000

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

int dp[MAX_N+1][MAX_W+1];
int N, W, v[MAX_N], w[MAX_N];

int main(){
  scanf("%d%d", &N, &W);
  rep(i, N) scanf("%d%d", v+i, w+i);

  rep(i, N) rep(j, W+1){
    if(j < w[i]) dp[i+1][j] = dp[i][j];
    else dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]] + v[i]);
  }

  printf("%d\n", dp[N][W]);
  return 0;
}