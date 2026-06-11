#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  string s,t;
  cin>>s>>t;
  int cnt=0;
  rep(i,s.size()){
    if(s[i]==t[i])cnt++;
  }
  cout<<s.size()-cnt<<endl;
  return 0;
}