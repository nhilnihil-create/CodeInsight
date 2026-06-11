#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin>>s;
  int len=s.size();
  int ans=0;
  for(int i=0;i<len;i++){
    ans+=s[i]-'0';
  }
  if(ans%9==0)cout<<"Yes"<<endl;
  else{
    cout<<"No"<<endl;
  }
}