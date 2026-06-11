#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  map<string,int> mp;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    mp[s]++;
  }
  
  int maxcount=0;
  for(auto x:mp){
    maxcount=max(maxcount,x.second);
  }
  
  vector<string> ans;
  for(auto x:mp){
    if(x.second==maxcount){
      ans.push_back(x.first);
    }
  }
  sort(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
  }
  return 0;
}