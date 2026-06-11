#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define N 100000

int group[N];
vector<int> vec[N];
int n,m;

int dfs_visit(int x,int k){
  stack<int> S;
  S.push(x);
  while(!S.empty()){
    int u=S.top();S.pop();
    for(int i=0;i<vec[u].size();i++){
      int v=vec[u][i];
      if(group[v]==0){
        group[v]=k;
        S.push(v);
      }
    }
  }
}
void dfs(){
  int id=1;
  for(int i=0;i<n;i++){
    if(group[i]==0) dfs_visit(i,id++);
  }
}
int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int s,t;
    cin>>s>>t;
    vec[s].push_back(t);
    vec[t].push_back(s);
  }
  dfs();
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int a,b;
    cin>>a>>b;
    if((group[a]!=0&&group[b]!=0)&&group[a]==group[b]){
      cout<<"yes"<<"\n";
    }else{
      cout<<"no"<<"\n";
    }
  }
}

