#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int V,E;
struct edge{
  int from,to,cost;
};
int comp(edge& a,edge& b){
  if(a.cost>b.cost)return 1;
  else if(a.cost<b.cost)return -1;
  else return 0;
}
int par[10001];
int Rank[10001];
void init(int n){
  for(int i=0;i<n;i++){
    par[i]=i;
    Rank[i]=0;
  }
}
int find(int a);
bool same(int a,int b){
  return find(a)==find(b);
}
int find(int a){
  if(par[a]==a)return a;
  else find(par[a]);
}
void unite(int a,int b){
  if(find(a)==find(b))return;
  if(Rank[a]>Rank[b])par[b]=a;
  else {
    par[a]=b;
    if(Rank[a]==Rank[b])Rank[b]++;
  }
}
void Union(int a,int b){
  unite(find(a),find(b));
}
vector<pair<int,pair<int,int> > > e;
int main(){
  cin>>V>>E;
  for(int i=0;i<E;i++){
    int a,b,c;cin>>a>>b>>c;
    e.push_back(make_pair(c,make_pair(a,b)));
  }
  sort(e.begin(),e.end());
  //for(int i=0;i<E;i++)cout<<e[i].fi<<endl;
  ll ans=0;
  init(V);
  for(int i=0;i<E;i++){
    if(!same(e[i].se.fi,e[i].se.se)){
      //cout<<e[i].fi<<endl;
      ans+=e[i].fi;
      Union(e[i].se.fi,e[i].se.se);
    }
  }
  cout<<ans<<endl;
  return 0;
}