#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  int n,ans=0; cin>>n;
  for(int i=1;i<=n;i++){
    if(i%3==0||i%5==0)
      continue;
    ans+=i;
  }
  cout<<ans<<endl;
}