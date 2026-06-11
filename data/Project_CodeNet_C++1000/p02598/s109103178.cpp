#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast_I_O ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod = 1e9+7 , INF = 1e9 ,  mx = 200009 ;
bool val(int mid,int a[],int n,int k)
{
    int t=0,i,j;
    if(mid==0) return false;
    for(i=0;i<n;i++)
    {
        t+=(a[i]-1)/mid;
    }
    return t<=k;
}
main()
{
    fast_I_O;
    int i,j,m,x,y,sum=0,p=0;
    int  n , k;
    cin>>n>>k;
    int a[n];
    for(i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int l=0 , r=a[n-1],mid;
    while(l+1<r)
    {
        mid=(l+r)/2;
        if(val(mid,a,n,k)) r=mid;
        else l=mid;
    }
    cout<<r;
    return 0;
}