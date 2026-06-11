#include<iostream>
using namespace std;
int main()
{
     long long a,b,c,k,l,m;
     cin>>a>>b>>c>>k;
     if(a>=k)
     {
         cout<<k<<endl;
     }
     else
     {
         l=k-a;
         if(b>=l)
         {
             cout<<a<<endl;
         }
         else
         {
             m=l-b;
             cout<<(a-m)<<endl;
         }
     }
     return 0;
}