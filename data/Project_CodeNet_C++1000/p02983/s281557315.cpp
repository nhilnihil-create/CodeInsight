#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long long L,R;
  cin >> L >> R;
  for(int i=1;i<1000000;i++){
    if(L<=2019*i&&2019*i<=R){
      cout << "0" << endl;
      return 0;
    }
  }
  long long ans=2020;
  for(long long i=L;i<R;i++){
    for(long long j=i+1;j<=R;j++){
      long long num=(i*j)%2019;
      ans=min(ans,num);
    }
  }
  cout << ans << endl;
}
  
