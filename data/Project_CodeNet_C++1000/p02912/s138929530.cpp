#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rapido ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

void solve()
{
    int n;int m;cin>>n>>m;
    priority_queue<int>pq;
    for(int i=0;i<n;i++)
    {
        int k;cin>>k;
        pq.push(k);
    }
    while(m-- && !pq.empty())
    {
        int temp=pq.top();
        pq.pop();
        pq.push(temp/2);
    }
    int ans=0;
    while(!pq.empty())
    {
        ans+=pq.top();
        pq.pop();
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