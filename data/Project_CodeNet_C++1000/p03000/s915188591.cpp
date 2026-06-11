#include<bits/stdc++.h>
using namespace std;
int  main()
{
    int n,m;
    cin>>n>>m;
    int sum=0,ans=1;
    for(int i=0;i<n;i++)
    {
        int l;
        cin>>l;
        sum+=l;

        if(sum<=m)
        {
            ans++;
        }

    }
    cout<<ans<<endl;
    exit(0);
}
