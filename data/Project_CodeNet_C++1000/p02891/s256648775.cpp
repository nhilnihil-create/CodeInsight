#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,t;
  cin>>s;
  t=s+s;
  int n;
  cin >>n;
  long long kotae=0;
  for(int i=0;i<s.size()-1;i++){
    if(s[i]==s[i+1]){
      s[i+1]='A';
      kotae++;
    }
  }
  long long sa=0;
  for(int i=0;i<t.size()-1;i++){
    if(t[i]==t[i+1]){
      t[i+1]='B';
      sa++;
    }
  }
  sa-=2*kotae;
  long long ans=kotae*n+sa*(n-1);
  if(kotae==s.size()/2&&s.size()%2==1){
    ans=kotae*n+sa*(n-1)/2;
  }
  cout<<ans<<endl;
  return 0;
}