
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,p,i,r=2e18+1,r1,p1,q,sum=0,r2=2e18+1;
   cin>>n;
   p=sqrt(n);
   for(i=1; i<=p; i++)
   {
       if(n%i==0 && (i+(n/i))<r2)
       {
           r2=(i+(n/i));
       }
   }
   cout<<(r2)-2;
    }
