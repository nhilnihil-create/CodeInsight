#include<bits/stdc++.h>
using namespace std;
signed main(){
  int n,a,ans=0;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a;
    if(a%2==1&&i%2==1) ans++;
  }
  cout<<ans<<"\n";
}