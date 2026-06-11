#include <algorithm>
#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<list>
#include<stack>
#include<map>
#include<set>
#include<string>
#include <sstream>
#include<bitset>

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

const int MAX = 100;


enum col
  {
   WHITE = 0,
   GRAY =  1,
   BLACK = 2,
  };

using namespace std;
const int INF = 0x7fffffff;

int M[MAX][MAX];
col color[MAX];
int d[MAX];
int p[MAX];
int n;

void daikusutora(int s){
  int ii,vv;

  //初期化
  for(ii=0;ii<n;ii++){
    color[ii] = WHITE;
    d[ii] = INF;
    p[ii] = -1;
  }
  
  d[s] = 0;
  p[s] = -1;
  
  int mincost,u;
  while(1){
    mincost = INF;
    u = -1;

    //次に選ぶ頂点の決定
    for(ii=0;ii<n;ii++){
      if(color[ii] != BLACK && d[ii] < mincost){

        mincost = d[ii];
        u = ii;
        //cout << "u:" << u << endl;
      }
    }

    //ループの終了条件
    if(mincost == INF){
      break;
    }

    color[u] = BLACK;
    //cout << "color:" << u << endl;

    //次のパスの選択候補
    for(vv=0;vv<n;vv++){
      //未探索の頂点かつ u -> vv へのパスがある場合
      if(color[vv] != BLACK && M[u][vv] != INF){
        //次に探索する候補
        if(d[u] + M[u][vv] < d[vv]){
          //cout << "vv:" << vv << endl;
          d[vv] = d[u] + M[u][vv];
          //color[vv] = GRAY;
        }
      }
    }
    
  }
  
}

int main(){

  long ii,jj,kk;
  int u,k,v,c;
  vector<int> a;

  cin >> n;

  //初期化
  for(ii=0;ii<n;ii++){
    for(jj=0;jj<n;jj++){
      M[ii][jj] = INF;
    }
  }
  
  for(ii=0;ii<n;ii++){

    cin >> u >> k;
    //cout << "u:" << u << "k:" << k << endl;
    for(jj=0;jj<k;jj++){
      cin >> v >> c;
      M[ii][v] = c;
    }
    
  }

  //for(ii=0;ii<n;ii++){
  //  for(jj=0;jj<n;jj++){
  //    cout << M[ii][jj] << " " ;
  //  }
  //  cout << endl;
  //}

  daikusutora(0);

  for(ii=0;ii<n;ii++){
    cout << ii << " " << d[ii] << endl;
  }
  return 0;
}

