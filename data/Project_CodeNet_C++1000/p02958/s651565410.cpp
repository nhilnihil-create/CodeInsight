#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,i,count=0;
   cin>>n;
   int a[n],a1[n];
   for(i=0;i<n;i++)
   {
       cin>>a[i];
       a1[i]=a[i];
   }
   sort(a,a+n);
   for(i=0;i<n;i++)
   {
       if(a[i]!=a1[i])
       {
           count++;
       }
   }
   if(count==2 || count==0)
   {
       cout<<"YES";
   }
   else{
    cout<<"NO";
   }
}
