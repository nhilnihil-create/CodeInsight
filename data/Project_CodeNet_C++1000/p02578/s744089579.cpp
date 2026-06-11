#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,mx=0;
    long long ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mx=max(mx,x);
        ans+=mx-x;
    }
    cout<<ans<<endl;
    return 0;
}
