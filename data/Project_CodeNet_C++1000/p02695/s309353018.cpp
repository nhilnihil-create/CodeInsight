#include<iostream>
#include<vector>
using namespace std;
int main(){
  int n,m,q;
  cin>>n>>m>>q;
  vector<int> a(q),b(q),c(q),d(q);
  for(int i=0;i<q;++i){
    cin>>a[i]>>b[i]>>c[i]>>d[i];
    a[i]--;b[i]--;
  }
  int ans = 0;
  auto calc = [&](vector<int>& v){
    int res = 0;
    for(int i=0;i<q;++i){
      if(v[b[i]]-v[a[i]]==c[i])res+=d[i];
    }
    if(ans<res)ans=res;
  };
  auto dfs = [&](auto&& dfs,vector<int>& v)->void{
    if(size(v)==n){
      calc(v);
      return ;
    }
    int s = v.back();
    for(int i=s;i<=m;++i){
      v.emplace_back(i);
      dfs(dfs,v);
      v.pop_back();
    }
  };
  for(int i=1;i<=m;++i){
    vector<int> v = {i};
    dfs(dfs,v);
  }
  cout<<ans<<endl;
  
}