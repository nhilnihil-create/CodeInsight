#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int n=s.size();
  bool ans=true;
  for(int i=0;i<n;i+=2){
    if(s[i]=='L')ans=false;
  }
  for(int i=1;i<n;i+=2){
    if(s[i]=='R')ans=false;
  }
  if(ans)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}