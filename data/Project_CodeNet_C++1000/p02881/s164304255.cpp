#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
  LL n,ans=1001001001001; cin>>n;
  LL rn=sqrt(n);
  for(LL i=1;i<=rn;i++){
    if(n%i) continue;
    LL j=n/(double)i;
    ans=min(ans,i+j-2);
  }
  cout<<ans;
}