#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast_I_O ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fr(a,b) for(int i = a; i < b; i++)
const int mod = 1e9+7 , INF = 1e9 ,  mx = 100005 ;
main()
{
    fast_I_O;
    int i,j,n,m,x,y,sum=0,p=0,l=0,k,mn=LLONG_MAX,mx=LLONG_MIN;
    cin>>n;
    for(i=0;i<n;i++) 
    {
        cin>>x>>y;
        if(x==y) ++p;
        else p=0;
        if(p>=3) l=1;
    }
    if(l==1) cout<<"Yes";
    else cout<<"No";
    return 0;
}