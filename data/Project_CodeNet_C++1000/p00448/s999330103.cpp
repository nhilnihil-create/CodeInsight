#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#include<string>
#include<sstream>

#define f first
#define s second
#define mp make_pair

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

typedef unsigned int uint;
typedef long long ll;

int sb[10][10000];

int main(){
  int R, C;
  while(scanf("%d%d",&R,&C), R+C){
    REP(i,R) REP(j,C) scanf("%d",&sb[i][j]);
    int ans = 0;
    REP(k, (1<<R)){
      REP(i,R)
        if(k & (1<<i))
          REP(j,C)
            sb[i][j] = !sb[i][j];

      int cnt = 0;
      REP(j,C){
        int tmp = 0;
        REP(i,R)
          tmp += sb[i][j];
        cnt += max(tmp, R-tmp);
      }
      ans = max(ans, cnt);

      REP(i,R)
        if(k & (1<<i))
          REP(j,C)
            sb[i][j] = !sb[i][j];
    }
    printf("%d\n",ans);
  }
  return 0;
}