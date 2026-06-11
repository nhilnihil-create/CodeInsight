#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int c[110];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    int l=100,r=1;

    for(int i=0;i<n;i++)
    {
        cin>>c[i];
        l=min(l,c[i]);
        r=max(r,c[i]);
    }

    int ans=INF;

    for(int i=l;i<=r;i++)
    {
        int a=0;
        for(int j=0;j<n;j++)a+=(c[j]-i)*(c[j]-i);
        ans=min(ans,a);
    }

    cout<<ans;

    return 0;
}
