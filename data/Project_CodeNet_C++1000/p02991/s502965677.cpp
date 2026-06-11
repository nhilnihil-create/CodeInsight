#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll n,m,a,b,s,t,dist[1000001];
bool use[1000001];
vector<int> v[1000001];
queue<int> q;
ll get_node(int nod, int cod)
{
    return 3*nod+cod;
}
void bfs()
{
    q.push(s);
    use[s]=1;
    while(!q.empty())
    {
        int nod=q.front();
        use[nod]=1;
        for(auto nd:v[nod])
            if(use[nd]==0)
        {
            use[nd]=1;
            dist[nd]=dist[nod]+1;
            q.push(nd);
        }
        q.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        v[get_node(a,0)].pb(get_node(b,1));
        v[get_node(a,1)].pb(get_node(b,2));
        v[get_node(a,2)].pb(get_node(b,0));
    }
    cin>>s>>t;
    s=get_node(s,0);
    t=get_node(t,0);
    bfs();
    if(use[t]==0)
        cout<<-1;
    else
        cout<<dist[t]/3;
    return 0;
}
