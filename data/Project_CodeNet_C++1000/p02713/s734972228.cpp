#include<bits/stdc++.h>
using namespace std;
int m=1e9+7;
int fun(int a,int b)
{
    if(a==0)
        return b;
    return fun(b%a,a);
}
int gcd(int a,int b,int c)
{
    int result=fun(a,fun(b,c));
    return result;
}
int main()
{

   int  n;
   cin>>n;
   long sum=0;
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
       {
           for(int k=1;k<=n;k++)
           {
               sum+=gcd(i,j,k);
               sum=sum%m;
           }
       }
   }
    cout<<sum;
}
