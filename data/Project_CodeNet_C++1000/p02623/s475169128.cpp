#include<bits/stdc++.h>
#define ll long long
#define N 200010
using namespace std;
int n,m,ans=0;
ll a[N],b[N],k;
int main()
{
    a[0]=0;b[0]=0;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        b[i]+=b[i-1];
    }
    b[m+1]=2*1e18;
    //cout<<prev(upper_bound(b,b+1+m,99))-b<<endl;
    for(int i=0;i<=n;i++)
    {
        if(a[i]>k)break;
        int vt=prev(upper_bound(b,b+2+m,k-a[i]))-b;
        ans=max(ans,vt+i);
    }
    cout<<ans;
    return 0;
}
