#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,i,sum=0;
   cin>>n;
   int a[n],b[n],c[n-1];
   for(i=0;i<n;i++)
   {
       cin>>a[i];
   }
   for(i=0;i<n;i++)
   {
       cin>>b[i];
   }
   for(i=0;i<n-1;i++)
   {
       cin>>c[i];
   }
   for(i=0;i<n;i++)
   {
       //cout<<b[a[i]-1]<<" ";
       sum=sum+b[a[i]-1];
   }
   //cout<<sum;
   for(i=0;i+1<n;i++)
    {
       if(a[i]+1==a[i+1])
       {
           //cout<<i<<" "<<c[i]<<endl;
           //cout<<a[i+1]<<" == "<<a[i]+1;
           sum=sum+c[a[i]-1];
       }
   }
   cout<<sum;
}
