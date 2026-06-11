#include <bits/stdc++.h>
#define N 100000
using namespace std;

int child[N][20];
int parent[N];
int depth[N];
int k[N];
int root;

char str[3][20] = {"root","internal node","leaf"};

void pr(int id){
  int type;
  if(parent[id] == -1) type = 0;
  else if(k[id] > 0) type = 1;
  else if(k[id] == 0) type = 2;

  
  printf("node %d: parent = %d, depth = %d, %s, [", id, parent[id], depth[id], str[type]);
  for(int i=0;i<k[id];i++){
    if(i)printf(", ");
    printf("%d",child[id][i]);
  }
  printf("]\n");
}

void dfs(int id,int dep){
  depth[id] = dep;
  for(int i=0;i<k[id];i++)dfs(child[id][i],dep+1);
}

int main(){
  int n;
  cin>>n;
  memset(parent,-1,sizeof(parent));
  for(int i=0,id;i<n;i++){
    cin>>id;
    cin>>k[id];
    for(int j=0;j<k[id];j++){
      cin>>child[id][j];
      parent[ child[id][j] ] = id;
    }
  }
  
  for(int i=0;i<n;i++) if(parent[i] == -1) root = i;
  dfs(root,0);
  for(int i=0;i<n;i++)pr(i);

  return 0;
}