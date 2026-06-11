#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
struct Graph{
  Graph(int n):E(n),d(n){}
  vector<vector<P>>E;
  vector<int>d;
  void add_edge(int a,int b,int c){
    E[a].push_back({b,c});
  }
  void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P>>q;
    fill(d.begin(),d.end(),1e9);
    q.push({d[s]=0,s});
    while(q.size()){
      P p=q.top();q.pop();
      if(p.first>d[p.second])continue;
      for(P& a:E[p.second]){
        int x=a.first,y=a.second+p.first;
        if(y<d[x])d[x]=y,q.push({y,x});
      }
    }
  }
};
main(){
  int n,a,b,c,x=0,y,z=1e9,g;
  while(cin>>n,n){
    Graph E(10);
    x=0,z=1e9;
    for(int i=0;i++<n;x=max(x,max(a,b)),E.add_edge(a,b,c),E.add_edge(b,a,c))cin>>a>>b>>c;
    for(int i=0;i<=x;++i){
      E.dijkstra(i);
      y=0;
      for(int j=0;j<=x;++j)y+=E.d[j];
      if(y<z)z=y,g=i;
    }
    cout<<g<<' '<<z<<endl;
  }
}