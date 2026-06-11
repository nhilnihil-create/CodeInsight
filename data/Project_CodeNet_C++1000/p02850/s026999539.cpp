#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int maxn=2e5+10;
const int mod=998244353;
int n;
vector<pair<int,int>>E[maxn];
vector<pair<int,int>>ans;
int f[maxn];
int max1=0;
bool cmp(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second;
}

void dfs(int u,int fa)
{
    int cnt=0;
    for(auto &v:E[u])
    {
        int z=v.first;
        if(z==fa)
            continue;
        cnt++;
        if(f[u]==cnt)
            cnt++;
        max1=max(max1,cnt);
        ans.pb({cnt,v.second});
        f[z]=cnt;
        dfs(z,u);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        E[u].pb({v,i});
    }
    dfs(1,0);
    sort(ans.begin(),ans.end(),cmp);
    cout<<max1<<'\n';
    for(auto &v:ans)
        cout<<v.first<<'\n';






}
