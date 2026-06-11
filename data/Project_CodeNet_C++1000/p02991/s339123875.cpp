#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int inf = 1001001001;
int main(){
  int N,M,S,T,i,u,v;scanf("%d%d",&N,&M);
  vector<int> G[N];
  for(i=0;i<M;i++){
    scanf("%d%d",&u,&v);u--;v--;
    G[u].push_back(v);
  }
  scanf("%d%d",&S,&T);S--;T--;
  int D[N][3];
  for(i=0;i<N;i++) fill(D[i],D[i]+3,inf);
  D[S][0] = 0;
  queue<pair<int,int>> q;q.push(make_pair(S,0));
  int fn,fd;
  while(!q.empty()){
    fn = q.front().first;fd = q.front().second;q.pop();
    for(i=0;i<G[fn].size();i++){
      if(D[G[fn][i]][(fd+1)%3] == inf){
        D[G[fn][i]][(fd+1)%3] = D[fn][fd]+1;
        q.push(make_pair(G[fn][i],(fd+1)%3));
      }
    }
  }
  if(D[T][0] == inf) printf("-1\n");
  else printf("%d\n",D[T][0]/3);
}
