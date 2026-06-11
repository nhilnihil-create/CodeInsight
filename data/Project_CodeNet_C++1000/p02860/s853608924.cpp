#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  if(n%2)
    cout<<"No";
  else{
       string s1=s.substr(0,s.size()/2);
       string s2=s.substr(s.size()/2,s.size()/2);
    if(s1==s2)
      cout<<"Yes";
    else
      cout<<"No";
  }
  return 0;
}