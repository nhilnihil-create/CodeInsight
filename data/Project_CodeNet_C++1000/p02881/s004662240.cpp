#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,b,ans=1000000000000011;
  cin >> n;
  for(int64_t a=1;a*a<=n;a++){
    if(n%a==0){
      b=n/a;
      ans=min(ans,a+b-2);
    }
  }
  cout << ans << endl;
}
