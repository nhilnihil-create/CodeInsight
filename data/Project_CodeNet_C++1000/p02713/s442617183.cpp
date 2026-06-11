#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                int z=__gcd(i,j);
                int y=__gcd(z,k);
                ans+=y;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

