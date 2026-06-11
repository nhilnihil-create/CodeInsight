#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)
#define MAX_V 100001

struct edge{
    int to,num;
};
vector<edge> G[MAX_V];

void input_graph(int E){
    int s,t;
    REP(i,E){
        cin>>s>>t;s--;t--;
        G[s].push_back({t,i});
        G[t].push_back({s,i});
    }
}

int main(){
  int V,E,k=0;cin>>V;E=V-1;
  input_graph(E);
  queue<int> q;q.push(0);
  vector<bool> used(V,false);used.at(0)=true;
  vector<int> ans(E,0),color_from(V,0);

  while(!q.empty()){
    int now=q.front(),color_now=1;q.pop();
    REP(i,G[now].size()){
      int next=G[now].at(i).to;
      if(!used.at(next)){
        used.at(next)=true;
        if(color_now==color_from.at(now)) color_now++;
        color_from.at(next)=ans.at(G[now].at(i).num)=color_now++;
        k=max(k,color_now-1);
        q.emplace(next);
      }
    }
  }
  
  cout<<k<<endl;
  REP(i,E) cout<<ans.at(i)<<endl;
}