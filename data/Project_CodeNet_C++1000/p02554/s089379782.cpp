#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t,i,k,n,x,y=1,z=1,s=1;
    cin>>n;
   for(i=0;i<n;i++)
   {
       s=(s*10)%1000000007;
   }
    for(i=0;i<n;i++)
   {
       y=(y*9)%1000000007;
   }
    for(i=0;i<n;i++)
   {
       z=(z*8)%1000000007;
   }
   cout<<(((s-(2*y)+z)%1000000007)+1000000007)%1000000007;

    return 0;
}
