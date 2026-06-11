#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;
  cin>>N;
  if(N%2==1)
    cout<<0<<endl;
  else{
    int ans=0;
    for(N/=10;N>0;N/=5)
      ans+=N;
    cout<<ans<<endl;
  }
}