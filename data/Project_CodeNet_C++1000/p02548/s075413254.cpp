#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t=1,i,j,k=0,q,p,x,y,n,a,b,d;
    //cin>>t;
    while(t--)
    {
       cin>>n;
       ll cnt=0;
       for(i=1;i<=n;i++)
       {
           k=n/i;
           cnt+=k;
           if(n%i==0)
           {
               cnt-=1;
           }

       }
       cout<<cnt<<endl;
    }

    return 0;
}
