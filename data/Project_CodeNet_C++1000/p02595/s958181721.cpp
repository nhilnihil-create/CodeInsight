#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast_I_O ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod = 1e9+7 , INF = 1e9 ,  mx = 100005 ;
main()
{
    fast_I_O;
    int i,j,n,m,x,y,sum=0,p=0,l,d;
    cin>>n>>d;
    while(n--)
    {
        cin>>x>>y;
        double kk=(double)(x*x)+(double)(y*y);
        kk=sqrt(kk);
        if(kk<=(double)d)++p;
    }
    cout<<p;

    return 0;
}