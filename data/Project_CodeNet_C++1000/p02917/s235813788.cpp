#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    int b;
    cin>>b;
    int ans=b;
    int ib=b;

    for(int i=1;i<n-1;i++)
    {
        int b;
        cin>>b;

        ans+=min(ib,b);
        ib=b;
    }

    ans+=ib;

    cout<<ans<<"\n";

    return 0;
}
