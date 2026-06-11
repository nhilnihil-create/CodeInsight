#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,i,j,k,sum,temp;
  cin >> n;
  sum=0;
  for(i=1;i<=n;++i)
  {
   for(j=1;j<=n;++j)
   {temp=gcd(i,j);
    for(k=1;k<=n;++k)
    {
    sum=sum+gcd(temp,k);
    }
   }
  }

 cout << sum;

return 0;}