#include<bits/stdc++.h>
#include <chrono>
#define ll long long
#define N 1000000007
using namespace std;
using namespace std::chrono; 

void solve()
{
    string s;
    cin>>s;
    ll ans=0;
    for(auto i:s)
        ans+=(i-'0');
    if(ans%9==0)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;++i)
    {
        //cout<<"Case #"<<i<<": ";
        solve();
        //cout<<'\n';
    }
}