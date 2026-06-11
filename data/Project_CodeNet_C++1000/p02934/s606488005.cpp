#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,i;
   cin>>n;
   double l=0,x;
   double a[n];
   for(i=0;i<n;i++)
   {
       cin>>a[i];
       l=l+1/a[i];
   }
   x=1/l;
   cout<<x;


}
