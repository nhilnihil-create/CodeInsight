#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
using namespace std;
int V,E;
vector<int> G[100000];
int visited[10000];
int L[100000];
int s=0;
void visit(int n){
  if(visited[n]==0){
    visited[n]=1;
    for(int i=0;i<G[n].size();i++){
      visit(G[n][i]);
    }
    L[s++]=n;
  }
}
void topological(){
  for(int i=V-1;i>=0;i--){
    visit(i);
  }
}
int main(){
  scanf("%d %d",&V,&E);
  for(int i=0;i<E;i++){
    int s,t;
    scanf("%d %d",&s,&t);
    G[s].push_back(t);
  }
  topological();
  for(int i=V-1;i>=0;i--)printf("%d\n",L[i]);
  return 0;
}