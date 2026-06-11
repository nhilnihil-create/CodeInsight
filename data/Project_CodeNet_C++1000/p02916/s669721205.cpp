#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define forn(i,n) for(int i=0;i<(int) n;i++)
#define Forn(i,n) for(int i=1;i<=(int) n;i++)
   int a[25];
   int b[25];
   int c[25];
int main()
{
   int n,i;
   cin>>n;

   for(i=1;i<=n;i++) cin>>a[i];

   for(i=1;i<=n;i++) cin>>b[i];
   for(i=1;i<n;i++) cin>>c[i];
   int sum=0;
    for(i=1;i<=n;i++)
    {
        sum+=b[a[i]];
        if(i!=1 && a[i]-a[i-1]==1)
        {
            sum+=c[a[i-1]];
        }
    }
   cout<<sum;
}




