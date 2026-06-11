#include <bits/stdc++.h>
using namespace std;
#define rapido ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

void solve()
{
    string s;string t;cin>>s>>t;
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==t[i])
        ans++;
    }
    cout<<ans<<endl;
}
int32_t main()
{
    rapido;
    int t;
    //cin>>t;
    t=1;
    while(t--)
    solve();
}