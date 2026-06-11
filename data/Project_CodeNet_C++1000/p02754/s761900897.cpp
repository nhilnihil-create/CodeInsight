#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t n,b,r;
  cin >> n >> b >> r;
  int64_t ans=0;
  ans=n/(b+r);
  ans*=b;
  ans+=min(n%(b+r),b);
  cout << ans << endl;
  return 0;
}