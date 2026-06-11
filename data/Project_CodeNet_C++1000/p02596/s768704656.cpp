#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast_I_O ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod = 1e9+7 , INF = 1e9 ,  mx = 100005 ;
main()
{
    fast_I_O;
    int i,j,n,m,x,y,sum=0,p=0,l,k;
    cin>>n;
    for(i=1;i<=1e7;i++)
    {
        p=p*10+7;
        p%=n;
        if(p==0)
        {
            cout<<i;
            return 0;
        }
   }
   cout<<-1;
    return 0;
}