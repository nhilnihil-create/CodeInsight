#include <bits/stdc++.h>
using namespace std;
#define int long long
#define y1 zzz
#define fi first
#define se second
#define PII pair<int,int>
#define PII2 pair<int,PII >
#define PII3 pair<PII,int >
#define PII4 pair<PII,PII >
#define all(x) (x).begin(),(x).end()
#define pb push_back
int a[5010],n;
vector<int> adj[5010];
void bt(int base,int t,vector<int> v)
{
    vector<int> v2;
    for(auto it:v)
        if(it&1)a[it*base]=t;
        else v2.pb(it/2);
    if(v2.size())bt(base*2,t+1,v2);
}
void solve()
{
    cin>>n;
    vector<int> v;
    for(int i=1;i<=n;i++)v.pb(i);
    bt(1,1,v);
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
            cout<<a[j-i]<<" ";
        cout<<'\n';
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("XORQUERY.inp","r",stdin);
    //freopen("XORQUERY.out","w",stdout);
    //int test;cin>>test;while(test--)
    solve();
    return 0;
}
