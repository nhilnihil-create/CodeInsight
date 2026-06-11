#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

int main(){
  ll n,u,v;
  cin>>n;
  ll ans=n*(n+1)*(n+2)/6;
  for(int i=1;i<n;i++){
    cin>>u>>v;
    ans-=min(u,v)*(n+1-max(u,v));
  }
  cout<<ans<<endl;
}
