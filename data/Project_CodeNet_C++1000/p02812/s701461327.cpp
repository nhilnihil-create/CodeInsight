#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rapido ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

void solve()
{
    int n;string s;
    cin>>n>>s;
    int ans=0;
    for(int i=0;i<=n-3;i++)
    {
        string str=s.substr(i,3);
        if(str=="ABC")
        {
        ans++;
        i+=2;
        }
    }
    cout<<ans<<endl;
}
int32_t main()
{
    rapido;
    int t;
    // cin>>t;
    t=1;
    while(t--)
    solve();
}