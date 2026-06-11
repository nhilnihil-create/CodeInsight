#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 200000;
int N,D[MAX_N] = {};vector<int> v[MAX_N];
bool Visit[MAX_N] = {};
void dfs(int s){
  Visit[s] = 1;
  for(int i=0;i<v[s].size();i++){
    if(!Visit[v[s][i]]){
      D[v[s][i]] += D[s];
      dfs(v[s][i]);
    }
  }
}
int main(){
  int Q,i,a,b,p,x;scanf("%d%d",&N,&Q);
  for(i=0;i<N-1;i++){
    scanf("%d%d",&a,&b);a--;b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for(i=0;i<Q;i++){
    scanf("%d%d",&p,&x);p--;
    D[p] += x;
  }
  dfs(0);
  for(i=0;i<N;i++) printf("%d ",D[i]);
  printf("\n");
}