#include <bits/stdc++.h>
using namespace std;

using Graph=vector<vector<int>>;

int main(){
  int N,M,S,T;
  cin>>N>>M;
  Graph G(N);
  for(int i=0;i<M;++i){
    int u,v;
    cin>>u>>v;
    --u,--v;
    G[u].push_back(v);
  }
  cin>>S>>T;
  --S,--T;

  queue<vector<int>> que;
  vector<vector<bool>> ch(N,vector<bool>(3,false));
  vector<int> v={S,0,0};
  que.push(v);
  ch[S][0]=true;
  int ans=-1;
  while(!que.empty()){

    auto w=que.front();
    que.pop();
    int x=w[0],y=w[1],z=w[2];
    //cout<<x<<y<<endl;

    if(x==T && y==0){
      ans=z;
      break;
    }
    else{
      if(y!=2){
        for(auto nv:G[x]){
          if(!ch[nv][y+1]){
            ch[nv][y+1]=true;
            vector<int> nw={nv,y+1,z};
            que.push(nw);
          }
        }
      }
      else if(y==2){
        for(auto nv:G[x]){
          if(!ch[nv][0]){
            ch[nv][y+1]=true;
            vector<int> nw={nv,0,z+1};
            que.push(nw);
          }
        }
      }
    }
  }

  cout<<ans<<endl;
}