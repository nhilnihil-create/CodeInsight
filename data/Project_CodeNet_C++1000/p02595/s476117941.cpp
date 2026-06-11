#include<bits/stdc++.h>
#define int long long int
#define mod 998244353 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w", stdout);
    #endif
    IOS;
    int n,d,ans=0;
    cin>>n>>d;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        if(x*x+y*y<=d*d)
        {
            ans++;
        }
    }
    cout<<ans<<"\n";
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}       