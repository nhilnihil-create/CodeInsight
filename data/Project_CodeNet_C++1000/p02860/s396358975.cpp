#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
   int t,flag=1;
   cin>>t;
   int i,n,r;
   char s[t+5];
   for(i=0;i<t;i++)
   {
       cin>>s[i];
   }

   n=t/2;
   r=t%2;
   if(r!=0)
   {
       flag  = 0;
   }
   else if(r==0)
   {
       for(i=0;i<n;i++)
       {
           if(s[i]!=s[i+n])
           {
               flag=0;
               break;
           }
       }
   }

   if(flag)
   {
       cout<<"Yes"<<'\n';
   }
   else
   {
       cout<<"No"<<'\n';
   }

    return 0;
}
