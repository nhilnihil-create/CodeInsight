#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int64_t r,l;
  cin >> l>>r;
  int64_t ans=2020;
  if(r-l>2020){
    cout << 0;
    return 0;
  }
  int64_t i,j=l;
  for(int64_t i=l;i<r;i++){
    for( j=i+1;j<=r;j++){
      int64_t mini=(i*j)%2019;
      ans=min(ans,mini);
      
    }
  }
  cout << ans;
}
