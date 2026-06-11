#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,m;
   cin>>n>>m;
   int arr[n+1];
   double sum=0;
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
       sum+=arr[i];
   }
  
   int count=0;
   
   for(int i=0;i<n;i++)
   {
       if(arr[i]>=(sum/(4*m)))
       {
           count++;
       }
      
   }
   if(count<m)
   {
       cout<<"No";
   }
   else
   {
       cout<<"Yes";

   }
}
