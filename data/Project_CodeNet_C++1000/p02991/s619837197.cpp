#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;

int main(){

  ll n,m;
  cin >> n>> m;
  vector<vector<ll>> G(n);
  for(int i=0;i<m;i++){
    ll u,v;
    cin >> u >> v;
    G[u-1].push_back(v-1);
  }
  ll s,t;
  cin >> s >> t;
  ll dist[n];
  for(int i=0;i<n;i++)dist[i]=-1;
  dist[s-1]=0;
  queue<ll> q;
  q.push(s-1);

  bool first[n];//1歩目で来たことがあるか
  bool second[n];//2ほめで来たことがあるか
  for(int i=0;i<n;i++){
    first[i]=false;
    second[i]=false;
  }

  while(!q.empty()){
    ll a=q.front();
    q.pop();

    for(int i=0;i<G[a].size();i++){
      if(first[G[a][i]])continue;
      else first[G[a][i]]=true;
      for(int j=0;j<G[G[a][i]].size();j++){
        if(second[G[G[a][i]][j]])continue;
        else second[G[G[a][i]][j]]=true;
        for(int k=0;k<G[G[G[a][i]][j]].size();k++){
          if(dist[G[G[G[a][i]][j]][k]]==-1){
            dist[G[G[G[a][i]][j]][k]]=dist[a]+1;
            q.push(G[G[G[a][i]][j]][k]);
          } 
        }
      }
    }

  }

  cout << dist[t-1] << endl;


}