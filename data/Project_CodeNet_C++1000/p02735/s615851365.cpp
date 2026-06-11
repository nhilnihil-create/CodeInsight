#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define Rep(i,n) for(intl i=0;i<(intl)(n);i++)
#define Rep1(i,n) for(intl i=1;i<(intl)(n)+1;i++)
#define vec vector
#define fi first
#define se second
#define pushb push_back
#define popb pop_back
#define SortA(v) sort(v.begin(), v.end())
#define SortD(v) sort(v.rbegin(), v.rend())
using intl = int64_t;
using vi = vec<intl>;
using vvi = vec<vi>;
vec<intl> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vec<intl> dy = {1, 0, -1, 0, 1, -1, 1, -1};

int main(){
  intl H,W;
  cin >> H>>W;
  vvi chizu(H,vi(W,0));
  vvi mindp(H,vi(W,0));
  Rep(i,H){
    Rep(j,W){
      char WB;
      cin >> WB;
      chizu[i][j]=(WB=='.')?1:0;
    }
  }
  
  mindp[0][0]=0;
  Rep1(j,W-1){
    mindp[0][j]=(chizu[0][j-1] - chizu[0][j]>0)?
      mindp[0][j-1]+1 : mindp[0][j-1];
  }
  Rep1(i,H-1){
    mindp[i][0]=(chizu[i-1][0]-chizu[i][0]>0)?
      mindp[i-1][0]+1 : mindp[i-1][0];
  }
  
  Rep1(i,H-1){
    Rep1(j,W-1){
      mindp[i][j]=min(
        (chizu[i][j-1] - chizu[i][j]>0)?
        mindp[i][j-1]+1 : mindp[i][j-1],
        (chizu[i-1][j]-chizu[i][j]>0)?
        mindp[i-1][j]+1 : mindp[i-1][j]
        );
    }
  }
  cout<<( (chizu[0][0]==0)?mindp[H-1][W-1]+1:mindp[H-1][W-1] ) ;
}