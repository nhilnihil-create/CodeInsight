#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> arr[100005];
vector<int> visited(100005,0);

void dfs(int i)
{
    visited[i]++;
    for(auto j:arr[i])
    {
        if(!visited[j])
        {
            dfs(j);
        }
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    int comp = 0;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            comp++;
            dfs(i);
        }
    }
    cout<<comp-1<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    solve();
}



