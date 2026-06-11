#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>v[N];
bool vstd[N];
vector<pair<int,int> > e;
map<pair<int,int>,int> mp;
int col[N];
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;cin>>n;
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
    e.push_back({a,b});
  }
  queue<int> q;
  int hnhn=0;
  q.push(1);vstd[1]=true;
  while(q.size()){
    int node=q.front();
    //cout<<node<<endl;
    q.pop();
    if(hnhn<v[node].size()){
       hnhn=v[node].size();
    }
    int now=1;
    for(auto u:v[node]){
      if(vstd[u]) continue;
      if(now==col[node]){
        now++;
      }
      col[u]=now;
      mp.insert({{u,node},now});
      mp.insert({{node,u},now});
      now++;
      vstd[u]=1;
      q.push(u);
    }
  }
  cout<<hnhn<<endl;
  for(auto u:e) cout<<mp[u]<<endl;
  return 0;
}