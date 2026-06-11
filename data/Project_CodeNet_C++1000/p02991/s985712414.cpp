#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MOD 1000000007

int main(){
  int N,M,S,T;
  cin>>N>>M;
  Graph G(N);
  for(int i=0;i<M;i++){
    int u,v;
    cin>>u>>v;
    u--;v--;
    G.at(u).push_back(v);
  }
  cin>>S>>T;
  S--,T--;
  vector<vector<int>> visit(N,vector<int>(3,-3));
  queue<pair<int,int>> q;
  q.push(make_pair(S,0));
  visit.at(S).at(0)=0;
  while(!q.empty()){
    int v=q.front().first;
    int i=q.front().second;
    for(auto nv :G.at(v)){
      if(visit.at(nv).at((i+1)%3)==-3){
        visit.at(nv).at((i+1)%3)=visit.at(v).at(i)+1;
        q.push(make_pair(nv,(i+1)%3));
      }
    }
    q.pop();
  }

  cout<<visit.at(T).at(0)/3<<endl;
}
