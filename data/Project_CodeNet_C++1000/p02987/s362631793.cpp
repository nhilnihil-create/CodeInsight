#include<bits/stdc++.h>
using namespace std;
int main() {
  string s,ans="Yes";
  int i;
  map<char,int> m;
  cin>>s;
  for(i=0;i<4;i++){
    if(m.count(s.at(i))) m.at(s.at(i))++;
    else m[s.at(i)]=1;
  }
  if(m.size()!=2) ans="No";
  else{
    for(auto z:m) if(z.second!=2) ans="No";
  }
  cout<<ans<<endl;
}