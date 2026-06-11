#include<bits/stdc++.h>
using namespace std;
#define int long long int 
int32_t main()
{
  int n,k;
  cin>>n>>k;
  if(n%k==0)
    cout<<0<<endl;
  
  else if(n%k<k/2)
    cout<<n%k;
  else
    cout<<k-n%k;
  return 0;
  
  
}
  
  