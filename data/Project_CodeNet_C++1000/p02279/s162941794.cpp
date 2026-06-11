#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> G[100001];
int par[100001];
int root;
int main(){
  for(int i=0;i<100001;i++)par[i]=-1;
  cin >> n;
  for(int i=0;i<n;i++){
    int id,k;
    cin >> id >> k;
    int u;
    for(int i=0;i<k;i++){cin >> u;
      G[id].push_back(u);
      par[u]=id;
    }
  }
  for(int i=0;i<n;i++)if(par[i]==-1)root=i;

  for(int i=0;i<n;i++){
    int dep=0;
    int p=par[i];
    while(1){
      if(p==-1)break;
      p=par[p];
      dep++;
    }
    printf("node %d: parent = %d, depth = %d, ",i,par[i],dep);
    if(root==i)printf("root, ");
    else if(G[i].size()==0)printf("leaf, ");
    else printf("internal node, ");
    printf("[");
    for(int j=0;j<G[i].size();j++){
      printf("%d",G[i][j]);
      if(j==G[i].size()-1)break;
      printf(", ");
    }
    printf("]\n");
  }
  return 0;
}