#include<bits/stdc++.h>
using namespace std;

int main(void)
{
  int n,k;
  cin>>n>>k;
  if(k==1)
    cout<<0<<endl;
  else if(n<k)
   cout<<1<<endl;
  else if(n==k)
    cout<<0<<endl;
  else
    cout<<n-k<<endl;
  return 0;
}