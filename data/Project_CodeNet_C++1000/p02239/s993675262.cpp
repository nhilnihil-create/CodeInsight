#include <iostream>
#include <sstream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define max 101
#define INF -1
#define WHITE 0
#define GRAY -1
#define BLACK 1
int n,color[max],d[max];
int varry[max][max];
void bfs(int s){
  queue<int>q;
  int u;
  for(int i=1;i<=n;i++){
    d[i]=INF;
  }
  color[s]=GRAY;
  d[s]=0;
  q.push(s);
  while(!q.empty()){
    u=q.front();
    q.pop();
    for(int i=1;i<varry[u][0]+1;i++){
      if(color[varry[u][i]]==WHITE){
	color[varry[u][i]]=GRAY;
	d[varry[u][i]]=d[u]+1;
	q.push(varry[u][i]);
      }
    }
    color[u]=BLACK;
  }

}
int main(){
  int u;
  cin>>n;
  for(int k=0;k<n;k++){
    cin>>u;
    cin>>varry[u][0];
    for(int i=0;i<varry[u][0];i++)
      cin>>varry[u][i+1];
  }
  bfs(1);
  for(int i=1;i<=n;i++)
    cout<<i<<" "<<d[i]<<endl;


  return 0;
}

