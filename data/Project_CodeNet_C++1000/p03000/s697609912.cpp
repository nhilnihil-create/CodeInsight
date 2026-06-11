#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    int d[n+2],l[n+1];
    d[1]=0;
    for(int i=1; i<=n; i++)
    {
        cin>>l[i];
    }
    for(int i=2; i<n+2; i++)
    {
        d[i]=d[i-1]+l[i-1];
    }
    int ans=0;
    for(int i=1; i<n+2; i++)
    {
        if(d[i]<=x)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
