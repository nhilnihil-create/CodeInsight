#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
int main() {
  string s;
  cin>>s;
  int ans=0;
  int tmp=0;
  for(int i=0;i<3;i++){
    if(s[i]=='R')
      tmp++;
    else{
      ans=max(ans,tmp);
      tmp=0;
    }
  }
  ans=max(ans,tmp);
  cout<<ans<<endl;
}