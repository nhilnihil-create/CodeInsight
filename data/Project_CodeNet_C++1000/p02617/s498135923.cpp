#include <bits/stdc++.h>

using namespace std;


int main(void){

  long long int ans=0,n,a,b;
  cin>>n;
  for(int i=1;i<=n;i++)
      ans+=(i*(n-i+1));

  for(int i=1;i<=n-1;i++)
  {
     cin>>a>>b;
     if(a>b)swap(a,b);
     ans-=(a*(n-b+1));
  }
  cout<<ans<<"\n";
  return 0;
}
