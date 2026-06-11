#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

vector<vector<int>>G;
vector<int>v;
vector<int>p;
vector<bool>f;

void dfs(int i,int sum)
{
    f[i] = true;
    sum += v[i];
    p[i] += sum;
    for(auto x: G[i])
    {
        if(f[x]) continue;
        dfs(x,sum);
    }
}

int main()
{
    int n,q;
    cin >> n >> q;
    G.resize(n);
    v.assign(n,0);
    for(int i = 0; i < n-1; i++)
    {
        int a,b;
        cin >> a >> b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < q; i++) 
    {
        int a,b;
        cin >> a >> b;
        a--;
        v[a] += b;
    }
    p.assign(n,0);
    f.assign(n,false);
    dfs(0,p[0]);
    for(int i = 0; i < n; i++) cout << p[i] << " ";
}