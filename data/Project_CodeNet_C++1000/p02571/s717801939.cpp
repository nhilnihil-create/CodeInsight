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
    string a,b;
    cin>>a>>b;
    int ans=999999;
    for (int i = 0; i <= a.size()-b.size(); ++i)
    {
        string c;
        int cn=0;
        c=a.substr(i,b.size());
        for (int j = 0; j < b.size(); ++j)
        {
            if (c[j]!=b[j])
            {
                cn++;
            }
        }
        ans=min(cn,ans);
    }
    cout<<ans;
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}       