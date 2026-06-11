#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<vector<int>> t(n);
  for(int _=1;_<n;_++){
    int u,v;
    cin>>u>>v;
    u--;
    v--;
    t.at(max(u,v)).push_back(min(u,v));
  }
  vector<int64_t> c(n);
  c[0]=1;
  for(int i=1;i<n;i++){
    c[i]=c[i-1]+i+1;
    for(int x:t.at(i))
      c[i]-=x+1;
  }
  int64_t s=0;
  for(int i=0;i<n;i++)
    s+=c[i];
  cout<<s<<endl;
}