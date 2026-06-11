#include <bits/stdc++.h>
using namespace std;
  
int main() {
  long long n,q;
  cin>>n>>q;
  vector<vector<long long>>c(n+1);
  for(int i=0;i<n-1;i++){
    long long a,b;
    cin>>a>>b;
    c[a].push_back(b);
    c[b].push_back(a);
  }
  vector<long long>ans(n+1);
  for(int i=0;i<q;i++){
    long long a,b;
    cin>>a>>b;
    ans[a]+=b;
  }
  vector<bool>p(n+1);
  p[1]=true;
  queue<long long>qq;
  qq.push(1);
  while(!qq.empty()){
    long long x=qq.front();
    qq.pop();
    for(int i=0;i<c[x].size();i++){
      if(!p[c[x][i]]){
        p[c[x][i]]=true;
        qq.push(c[x][i]);
        ans[c[x][i]]+=ans[x];
      }
    }
  }
  for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
}