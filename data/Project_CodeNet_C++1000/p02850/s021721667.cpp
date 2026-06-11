#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
typedef pair<ll,ll> P;

vector<int>ans;
vector<vector<P>>d;
void dfs(int x,int y,int z){
  int co=1;
  rep(i,d[x].size()){
    int k=d[x][i].first;
    int v=d[x][i].second;
    if(k!=z){
      if(co==y){
        co++;
      }
      ans[v]=co;
      dfs(k,co,x);
      co++;
    }
  }
}
    
int main() {
  int n;
  cin>>n;
  vector<int>a(n-1),b(n-1);
  d.resize(n);
  ans=vector<int>(n-1);
  rep(i,n-1) {
    cin>>a.at(i)>>b.at(i);
    a.at(i)--;b.at(i)--;
    d[a.at(i)].push_back(P(b.at(i),i));
    d[b.at(i)].push_back(P(a.at(i),i));
  }
  int s=0;
  rep(i,n){
    int si=d[i].size();
    s=max(s,si);
  }
  cout<<s<<endl;
  dfs(0,-1,-1);
  rep(i,n-1){
    cout<<ans[i]<<endl;
  }
}