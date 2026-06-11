#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long int h,w,n,m;
  cin>>h>>w>>n;
  m=max(h,w);
  if(n%m==0)
    cout<<n/m;
  else
    cout<<(n/m)+1;
}
