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
    vector<int>a(n+1,0);
    
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=n;j+=i)
        {
            a[j]++;
        }
    }
    for(i=1;i<=n;i++)
    {
        p+=(i*a[i]);
    }
    cout<<p;
    return 0;
}