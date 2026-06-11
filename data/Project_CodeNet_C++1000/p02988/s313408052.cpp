#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,i,ans=0;
  cin>>n;
  vector<int> p(n);
  for(i=0;i<n;i++) cin>>p.at(i);
  for(i=1;i<n-1;i++) if((p.at(i+1)-p.at(i))*(p.at(i-1)-p.at(i))<0) ans++;
  cout<<ans<<endl;
}