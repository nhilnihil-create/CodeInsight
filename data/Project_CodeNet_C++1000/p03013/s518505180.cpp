#include<bits/stdc++.h>
using namespace std;
int64_t mod=1e9+7;
int main() {
  int64_t n,m,i,ans=1;
  cin>>n>>m;
  vector<int64_t> a(m+2),b(n+1);
  a.at(0)=-1;
  a.at(m+1)=n+1;
  for(i=1;i<=m;i++) cin>>a.at(i);
  b.at(0)=1;
  b.at(1)=1;
  for(i=2;i<=n;i++) b.at(i)=(b.at(i-2)+b.at(i-1))%mod;
  for(i=1;i<=m+1;i++){
    if(a.at(i)-a.at(i-1)==1){
      ans=0;
      break;
    }
    else ans=ans*b.at(a.at(i)-a.at(i-1)-2)%mod;
  }
  cout<<ans<<endl;
}