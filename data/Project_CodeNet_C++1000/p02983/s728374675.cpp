#include <bits/stdc++.h>
using namespace std;


int main() {
  long L,R;
  cin>>L>>R;
  long ans=1234567890;
  for(long i=L;i<R;i++){
    for(long j=i+1;j<=R;j++){
      ans=min((i*j)%2019,ans);
      if(ans==0){
        cout<<0<<endl;
        return 0;
      }
    }
  }
  cout<<ans<<endl;
  }
