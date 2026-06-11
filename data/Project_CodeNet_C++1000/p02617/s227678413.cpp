#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int64_t>>;
int main(){
  int64_t N;cin>>N;
  Graph G(N);
  for(int i=0;i<N-1;i++){
  int64_t u,v;cin>>u>>v;u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }vector<int64_t>C(N);C.at(0)=1;
  for(int i=1;i<N;i++){
  int64_t a=C.at(i-1)+i+1;
    for(auto v:G[i]){
    if(v<i)
      a-=(v+1);
    }C[i]=a;
   }int64_t ans=0;
  for(int i=0;i<N;i++)
    ans+=C.at(i);
  cout<<ans<<endl;
  return 0;
}