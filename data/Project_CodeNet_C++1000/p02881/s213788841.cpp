#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t n;
  cin >> n;
  int64_t ans=2e12;
  for(int i=1;i<=sqrt(n);i++){
    if(n%i==0)
      ans=min(ans,i+n/i-2);
  }
  cout << ans << endl;
  return 0;
}