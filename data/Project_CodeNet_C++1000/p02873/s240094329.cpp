#include <bits/stdc++.h>
using namespace std;
int sum[500010];
int main(){
  string s;
  cin>>s;
  for(int i=0;i<s.size();++i){
    if(s[i]=='<') sum[i+1]=sum[i]+1;
  }
  for(int i=s.size()-1;i>=0;--i){
    if(s[i]=='>') sum[i]=max(sum[i],sum[i+1]+1);
  }
  long long ans = 0;
  for(int i=0;i<s.size()+1;i++) ans+=sum[i];
  cout<<ans<<endl;
}