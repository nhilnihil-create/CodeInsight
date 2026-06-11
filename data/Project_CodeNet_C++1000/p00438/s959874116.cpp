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

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

int road[16][16], a, b, point[16][16];

int main(){
  while(scanf("%d%d", &a, &b) && a+b){
    memset(road, 0, sizeof(road));
    memset(point, 0, sizeof(point));
    int n, x, y;
    scanf("%d", &n);
    rep(i, n){
      scanf("%d%d", &x, &y); --x; --y;
      point[y][x] = 1;
    }

    road[0][0] = 1;
    REP(i, 1, a) if(!point[0][i]) road[0][i] = road[0][i-1];
    REP(i, 1, b) if(!point[i][0]) road[i][0] = road[i-1][0];
    REP(i, 1, b) REP(j, 1, a) if(!point[i][j]) road[i][j] = road[i-1][j] + road[i][j-1];

    printf("%d\n", road[b-1][a-1]);
  }
  return 0;
}