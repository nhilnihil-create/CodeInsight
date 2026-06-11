#include <bits/stdc++.h>
using namespace std;
long long a=2019;
int main(){
  long long L,R; cin>>L>>R;
  if(L+2019<R){cout<<0<<endl; return 0;}
  L%=a; R%=a;
  if(L>=R){cout<<0<<endl; return 0;}
  long long ans=2000000;
  for(long long i=L;i<=R;i++){
    for(long long j=L;j<=R;j++){
      if(j==i)continue;
      ans=min(ans,(i*j)%a);
    }
  }
  cout<<ans<<endl;
}