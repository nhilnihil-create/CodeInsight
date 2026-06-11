#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,i,ans=0;
  cin>>n;
  vector<int> a(n),b(n),c(n-1);
  for(i=0;i<n;i++) cin>>a.at(i);
  for(i=0;i<n;i++) cin>>b.at(i);
  for(i=0;i<n-1;i++) cin>>c.at(i);
  for(i=0;i<n;i++) {
    ans+=b.at(i);
    if(i>0 && a.at(i-1)+1==a.at(i)) ans+=c.at(a.at(i-1)-1);
  }
  cout<<ans<<endl;
}