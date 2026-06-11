#include<bits/stdc++.h>
using namespace std;
#define int     long long
#define F       first
#define S       second
#define _READ   freopen("input.txt","r", stdin);
#define _FAST   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
void solve()
{
    int n;
    cin>>n;
    vector<int> ar(n);
    for(auto &i:ar)
        cin>>i;
    map<int,int> mp;
    for(int i=0;i<n;i++)
        mp[ar[i]+i]++;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(mp.count(i-ar[i]))
        {
            ans+=mp[i-ar[i]];
        }
    }
    //ans/=2;
    cout<<ans;
}
int32_t main()
{
    _FAST
    int t;
    t=1;
    //cin>>t;
    while(t--)
        solve();
    
    return 0;
}