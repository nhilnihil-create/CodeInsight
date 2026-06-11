#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

int main() {
  string s;
  cin>>s;
  int bigger[s.size()],smaller[s.size()];
  for(int i=0;i<s.size();i++){
    if(i==0){
      if(s[i]=='<') bigger[i]=1;
      else bigger[i]=0;
      continue;
    }
    if(s[i]=='<') bigger[i]=bigger[i-1]+1;
    else bigger[i]=0;
  }
  for(int i=s.size()-1;i>=0;i--){
    if(i==s.size()-1){
      if(s[i]=='>') smaller[i]=1;
      else smaller[i]=0;
      continue;
    }
    if(s[i]=='>') smaller[i]=smaller[i+1]+1;
    else smaller[i]=0;
  }
  ll sum=0;
  for(int i=0;i<s.size()+1;i++){
    if(i==0) sum+=smaller[0];
    else if(i==s.size()) sum+=bigger[s.size()-1];
    else sum+=max(bigger[i-1],smaller[i]);
  }
  cout<<sum<<endl;
  return 0;
}
