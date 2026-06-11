#include<bits/stdc++.h>
using namespace std;
int main()
{
   int t;
   double r,s=0;
   cin>>r;
   for(t=1; t<=r; t++)
   {
       if(t%2!=0)
        s++;
   }
   double d= s/r;
   printf("%0.7lf",d);
  return 0;
}