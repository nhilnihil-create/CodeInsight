#include<bits/stdc++.h>
using namespace std;
int main()
{
long long a,i,b,j;
cin>>a;
for(i=1;i<=5000000;i++)
{
  if((int)(i*1.08)==a)
  {
    cout<<i<<endl;
    return 0;
  }
}
  cout<<":("<<endl;
  return 0;
}
