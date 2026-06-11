#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n,k; cin>>n>>k;
  unordered_map<char,int> mp; cin>>mp['s']>>mp['p']>>mp['r'];
  string t; cin>>t;
  int res=0;
  for(int i=0; i<k; ++i){
    bool s=true;
    for(int j=i; j<n; j+=k)
      res+=(s==true? mp[t[j]]:0),s=((s==true)&&(t[j+k]==t[j])? false:true);
  }
  cout<<res;
  return 0;
}