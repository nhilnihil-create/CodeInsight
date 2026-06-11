#include<iostream>
#include<vector>

using namespace std;


int main(){
  int n,m;
  cin>>n>>m;
  int h[100001];
  for(int i=1;i<=n;i++){
    cin>>h[i];
  }
  vector<int> G[100001];
  while(m--){
    int a,b;
    cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    int mx=0;
    for(auto e:G[i]){
      mx=max(mx,h[e]);
    }
    ans+=h[i]>mx;
  }
  cout<<ans<<endl;
}
