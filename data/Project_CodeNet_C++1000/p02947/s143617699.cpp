#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >>n;
  map<string,int>mp;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    if(mp.count(s))mp[s]++;
    else mp[s]=1;
  }
  long long kotae=0;
  long long kazu=0;
  auto begin=mp.begin(),end=mp.end();
  for(auto iter=begin;iter!=end;iter++){
    kazu=iter->second;
    if(kazu>1){
      kotae+=kazu*(kazu-1)/2;
    }
  }
  cout<<kotae<<endl; 
  return 0;
}
  
