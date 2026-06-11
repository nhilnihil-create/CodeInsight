#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int N;cin>>N;
  
  ll ans=0;
  int sta;cin>>sta;
  for(int i=1;i<N;i++){
    int next;cin>>next;
    if(sta<next)sta=next;
    else ans+=sta-next;
  }
  
  cout<<ans<<endl;
  return 0;
}