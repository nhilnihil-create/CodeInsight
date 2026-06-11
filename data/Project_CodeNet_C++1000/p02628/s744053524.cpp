#include<bits/stdc++.h>
using namespace std;
int p[1001];
int main()
{
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    sort(p,p+n+1);
    for(int i=1;i<=k;i++)
        ans+=p[i];
    cout<<ans<<endl;
    return 0;
}
