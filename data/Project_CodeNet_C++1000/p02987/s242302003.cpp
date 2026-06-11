#include <bits/stdc++.h>
using namespace std;
signed main(){
  string s;
  cin>>s;
  unordered_map<char,int> m;
  for(int i=0;i<4;i++){
    m[s[i]]++;
  }
  for(auto p:m){
    if(p.second!=2){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}