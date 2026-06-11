#include <bits/stdc++.h>
#define LL long long
#define PII pair<int,int>
#define PIL pair<int,LL>
#define PLI pair<LL,int>
#define PIII pair<int,PII>
#define PLL pair<LL,LL>
#define PLII pair<LL,PII>
#define VI vector<int>
#define VVI vector<VI>
#define VL vector<LL>
#define VVL vector<VL>
#define VPII vector<PII>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define all(x) x.begin(),x.end()
#define watch(x) cout<<(#x)<<" = "<<(x)<<'\n'
#define mset(a,v) memset(a,v,sizeof(a))
#define setp(x) cout<<fixed<<setprecision(x)
#define EPS 0.00000000001
#define PI acos(-1)
#define loop(i,b,n) for(int i=b;i<n;++i)
#define rev_loop(i,b,n) for(int i=b;i>=n;--i)
using namespace std;

const int MOD = 1e9 + 7;
const LL MX = 1e5 + 100;
const LL INF = 1e9;

VI g[MX];
bool vis[MX];

void bfs(int s)
{
    int u, v;
    queue<int> q;

    vis[s] = true;
    q.push(s);

    while(!q.empty())
    {
        u = q.front(); q.pop();

        for(int i = 0;i < g[u].size(); ++i)
        {
            v = g[u][i];
            if(!vis[v])
            {
                vis[v] = true; q.push(v);
            }
        }
    }
}

int main()
{
    //ofstream out("output.txt");
    //ifstream in("input.txt");
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n, m, u, v;
    cin>>n>>m;

    loop(i,0,m)
    {
        cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }

    int ans = 0;
    loop(i,1,n+1)
    {
        if(!vis[i])
        {
            bfs(i);
            ++ans;
        }
    }

    --ans;
    cout<<ans<<'\n';

    return 0;
}
