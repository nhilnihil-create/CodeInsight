#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,k,s;cin>>n>>k>>s;

    int ans=(s==1e9?1:s+1);

    for(int i=0;i<n;i++)
    {
        if(i<k)cout<<s<<" ";
        else cout<<ans<<" ";
    }

    cout<<"\n";

    return 0;
}
