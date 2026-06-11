#include <iostream>
using namespace std;
#define N 100
#define INF 9999999
int M[N][N];
int mincost[N];
bool used[N];
int n;
int prim(){
  for(int i=0;i<n;i++){
    used[i]=false;
    mincost[i]=INF;
  }
  mincost[0]=0;
  int res=0;

  while(true){
    int v=-1;
    for(int i=0;i<n;i++){
      if(!used[i] && (v==-1||mincost[i]<mincost[v])){
        v=i;
      }
    }
    if(v==-1) break;
    used[v]=true;
    res+=mincost[v];

    for(int i=0;i<n;i++){
      mincost[i]=min(mincost[i], M[v][i]);
    }
  }
  return res;
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int e; cin>>e;
      M[i][j]=(e==-1)?INF:e;
    }
  }
  cout<<prim()<<"\n";

}

