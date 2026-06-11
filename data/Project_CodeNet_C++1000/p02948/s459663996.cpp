#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,m,a,b,i,ans=0;
  multiset<int> s;
  map<int,multiset<int>> mp;
  cin>>n>>m;
  for(i=0;i<n;i++){
    cin>>a>>b;
    if(a<=m){
      if(mp.count(a)) mp.at(a).insert(b);
      else mp[a].insert(b);
    }
  }
  for(i=1;i<=m;i++){
    if(mp.count(i)) for(auto j:mp[i]) s.insert(j);
    if(s.size()>0){
      auto it=prev(s.end(),1);
      ans+=*it;
      s.erase(it);
    }
  }
  cout<<ans<<endl;
}