#include <bits/stdc++.h>
using namespace std;

int main() {
  long L,R;
  cin>>L>>R;
  long ans=9099;
  bool flg=false;
  for(long i=L;i<R;i++){
    for(long j=i+1;j<=R;j++){
      ans=min(ans,(i*j)%2019);
      if(ans==0){
        flg=1;
        break;
      }
    }
    if(flg) break;
  }
  cout<<ans<<endl;
}
