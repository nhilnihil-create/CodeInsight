#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,v,p;
    cin>>n>>m>>v>>p;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int low=(-1);
    int up=n;
    while((up-low)!=1)
    {
        int k=(low+up)/2;
        int x=a[k];
        if(k>=(n-p))
        {
            up=k;
            continue;
        }
        x+=m;
        if(x<a[n-p])
        {
            low=k;
            continue;
        }
        if(v<=p)
        {
            up=k;
            continue;
        }
        int sum=0;
        for(int i=0;i<(n-p+1);++i)
        {
            sum+=min(max(0LL,x-a[i]),m);
        }
        sum+=(p-1)*m;
        if(sum>=(v*m))
        {
            up=k;
        }
        else
        {
            low=k;
        }
    }
    cout<<(n-up);
    return 0;
}
