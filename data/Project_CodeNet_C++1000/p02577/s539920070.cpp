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
    string s;
    cin>>s;
    int n,ans=0;
    n=s.size();
    for (int i = 0; i < n; ++i)
    {
        ans=(ans+(s[i]-'0'))%9;
    }
    if (ans==0)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}       