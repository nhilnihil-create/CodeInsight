#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n;
  int64_t a,b;
  cin>>n>>a>>b;
  int64_t c=a+b;
  int64_t ans=a*(n/c);
  ans+=min(n%c,a);
  cout<<ans<<endl;
  return 0;
}
  