#include<bits/stdc++.h>
#define int long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w", stdout);
    #endif
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int ans;
    ans=max(a*c,max(a*d,max(b*c,b*d)));
    cout<<ans;
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}       