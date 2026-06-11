#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,k; cin>>a>>b>>c>>k;
  int ans=0;
  if(a<=k){
    ans+=a;
    k-=a;
  }
  else{
    cout<<k<<endl;
    return 0;
  }
  if(b<=k)
    k-=b;
  else{
    cout<<ans<<endl;
    return 0;
  }
  if(c==k){
    ans-=c;
    cout<<ans<<endl;
  }
  else
    cout<<ans-k<<endl;
}