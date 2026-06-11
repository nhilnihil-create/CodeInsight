#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n,k;
  cin>>n>>k;
  vector<pair<int,int>> g;
  rep(i,n-2) for(int j=i+1;j<n-1;j++) g.pb({i,j});
  rep(i,n-1) g.pb({i,n-1});
  if(k>n*(n-1)/2-(n-1)){
    cout<<-1<<endl;
    return 0;
  }
  rep(i,k){
    g.erase(g.begin());
  }
  cout<<g.size()<<endl;
  rep(i,(int)g.size()) cout<<g[i].first+1<<" "<<g[i].second+1<<endl;
} 