#include <bits/stdc++.h>
using namespace std;

int main()
{
 long long int n,a,b, dem=0, d;
   cin>>n>>d;
   for (long long int i=1;i<=n;i++)
   {
       cin>>a>>b;
       if (sqrt(a*a+b*b)<=d) dem++;
   }
   cout<<dem;
    return 0;
}