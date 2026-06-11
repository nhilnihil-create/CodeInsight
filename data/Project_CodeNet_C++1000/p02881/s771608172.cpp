#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
  int64_t n,ans=10000000000000;
  cin>>n;
  for(int64_t i=1;i*i<=n;++i){
    if(n%i==0)
      ans=min(ans,i+n/i-2);
  }
  cout<<ans<<endl;
}