#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,d;
   cin>>n>>d;
   int c=0;
   while(n--)
   {
       long long x,y;
       cin>>x>>y;
       double sum=0;
       sum=sqrt(x*x+y*y);
       if(sum<=d)
       c++;
   }
   cout<<c<<endl;
   return 0;
    
}