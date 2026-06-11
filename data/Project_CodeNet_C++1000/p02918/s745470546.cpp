#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,k,i,ans=0;
  string s;
  cin>>n>>k>>s;
  for(i=0;i<n;i++){
    if(i>0 && s.at(i-1)==s.at(i) && s.at(i)=='L') ans++;
    else if(i<n-1 && s.at(i+1)==s.at(i) && s.at(i)=='R') ans++;
  }
  ans=min(ans+2*k,n-1);
  cout<<ans<<endl;
}