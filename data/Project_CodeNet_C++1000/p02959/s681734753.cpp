#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define forn(i,n) for(int i=0;i<(int) n;i++)
#define Forn(i,n) for(int i=1;i<=(int) n;i++)
lli a[100005];
lli b[100005];
int main()
{
   lli n,i;
   cin>>n;
   n++;
   for(i=1;i<=n;i++) cin>>a[i];

   for(i=1;i<n;i++) cin>>b[i];
   lli sum=0;
   for(i=1;i<n;i++)
   {
       if(a[i]>=b[i])
       {
            sum+=b[i];
           a[i]-=b[i];
           b[i]-=b[i];

       }
       else if(a[i]<b[i])
       {
           sum+=a[i];
           b[i]-=a[i];

       }
       if(b[i])
       {
           if(a[i+1]>b[i])
           {
               sum+=b[i];
               a[i+1]-=b[i];
           }
           else
           {
               sum+=a[i+1];
               a[i+1]=0;

           }
       }

   }
   cout<<sum;

}




