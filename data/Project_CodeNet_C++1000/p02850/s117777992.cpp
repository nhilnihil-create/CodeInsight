#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<set<int>>;

int main(){
  int N; cin>>N;
  vector<int> A(N),B(N);
  map<pair<int,int>,int> Edge;
  Graph G(N+1);
  rep(i,N-1){
    cin>>A.at(i)>>B.at(i);
    Edge[make_pair(A.at(i),B.at(i))] = -1;
    Edge[make_pair(B.at(i),A.at(i))] = -1;
    G.at(A.at(i)).insert(B.at(i));
    G.at(B.at(i)).insert(A.at(i));
  }

  int Colors = 1;
  rep1(i,N+1)Colors = max(Colors,(int)G.at(i).size());
  cout<<Colors<<endl;

  vector<bool> seen(N+1,false);
  queue<int> Q;
  Q.push(1);
  map<int,int> par;
  while(!Q.empty()){
    int v = Q.front();
    Q.pop();
    seen.at(v)=true;
    queue<int> CV;
    int banned_num = -1;
    if(v!=1){
      banned_num = Edge[make_pair(v,par[v])];
    }
    rep1(i,(int)G.at(v).size()+1){
      if(i!=banned_num)CV.push(i);
    }
    for(auto nv: G.at(v)){
      if(seen.at(nv))continue;
      int edge_color = CV.front();
      CV.pop();
      Edge[make_pair(v,nv)]=edge_color;
      Edge[make_pair(nv,v)]=edge_color;
      par[nv]=v;
      Q.push(nv);
    }
  }
  rep(i,N-1)cout<<Edge[make_pair(A.at(i),B.at(i))]<<endl;
}
