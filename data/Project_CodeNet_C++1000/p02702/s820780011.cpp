#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int n=s.length();
  long long ans=0;
  int mod=2019;
  long long suff=0;
  long long pot=1;
  vector<long long>cntsuff(mod,0);
  for(int i=n-1;i>=0;i--){
    int digit=s[i]-'0';
    suff=(suff+digit*pot)%mod;
    if(suff==0)
      ans++;
    pot=(pot*10)%mod;
    ans+=cntsuff[suff];
    cntsuff[suff]++;
  }
  cout<<ans<<endl;
}