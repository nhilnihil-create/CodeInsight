#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  map<char,int>mp;
  for(int i=0;i<s.size();i++){
    mp[s[i]]++;
  }
  if(mp.size()!=2){
    cout<<"No"<<endl;
    return 0;
  }
  for(auto a:mp){
    if(a.second!=2){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
}