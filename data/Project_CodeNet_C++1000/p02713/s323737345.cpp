#include<bits/stdc++.h>
using namespace std;
#define int long long

main()
{
    int k,ans=0;
    cin>>k;
    for(int i=1; i<=k; i++)
    {
        for(int j=1; j<=k; j++)
        {
            for(int m=1; m<=k; m++)
            {
                ans+=__gcd(i,__gcd(j,m));
            }
        }
    }
    cout<<ans<<endl;
}
