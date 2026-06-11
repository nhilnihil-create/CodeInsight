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
    int a[n];
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n-2;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            for(k=j+1;k<n;k++)
            {
                if(a[i]!=a[j] && a[j]!=a[k] && a[i]!=a[k] && (a[i]+a[j]>a[k] && a[j]+a[k]>a[i] && a[i]+a[k]>a[j])) ++p;
            }
        }
    }
    cout<<p<<endl;
    return 0;
}