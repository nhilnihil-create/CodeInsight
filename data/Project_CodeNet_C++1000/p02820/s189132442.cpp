#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k,r,s,p;
  string t;
  cin>>n>>k>>r>>s>>p>>t;
  vector<char>hand(k);
  int ans=0;
  for(int i=0;i<k;i++) hand[i]='a';
  for(int i=0;i<n;i++){
    if(t[i]=='r'){
      if(hand[i%k]=='p') hand[i%k]='a';
      else{
        ans+=p;
        hand[i%k]='p';
      }
    }
    if(t[i]=='s'){
      if(hand[i%k]=='r') hand[i%k]='a';
      else{
        ans+=r;
        hand[i%k]='r';
      }
    }
    if(t[i]=='p'){
      if(hand[i%k]=='s') hand[i%k]='a';
      else{
        ans+=s;
        hand[i%k]='s';
      }
    }
  }
  cout<<ans<<endl;
}