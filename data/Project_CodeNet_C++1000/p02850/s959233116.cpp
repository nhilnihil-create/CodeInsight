#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)
#define MAX_V 100001

struct edge{
    int to,color,num;
};
vector<edge> G[MAX_V];

void input_graph(int E){
    int s,t;
    REP(i,E){
        cin>>s>>t;s--;t--;
        G[s].push_back({t,-1,i});
        G[t].push_back({s,-1,i});
    }
}

int main(){
  int V,E,k=0;cin>>V;E=V-1;
  input_graph(E);
  queue<int> q;q.push(0);
  vector<bool> h(V,false);h.at(0)=true;
  vector<int> ans(E,0),edge_from(V,0);

  while(!q.empty()){
    int now=q.front();q.pop();
    int cur_color=1;
    for(int i=0;i<G[now].size();i++){
      int next=G[now].at(i).to;
      if(h.at(next)==0){
        h.at(next)=true;
        if(cur_color==edge_from.at(now)) cur_color++;
        G[now].at(i).color=edge_from.at(next)=cur_color;
        k=max(k,cur_color);
        ans.at(G[now].at(i).num)=cur_color;
        cur_color++;
        q.push(next);
      }
    }
  }
  
  cout<<k<<endl;
  REP(i,E) cout<<ans.at(i)<<endl;
}