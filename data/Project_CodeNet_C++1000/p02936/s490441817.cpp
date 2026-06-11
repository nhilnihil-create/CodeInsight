#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MODADD(ADD_X,ADD_Y)  (ADD_X+ADD_Y)%MOD;
#define MODSUB(SUB_X,SUB_Y)  (SUB_X-SUB_Y)+MOD)%MOD;
#define MODMUL(MUL_X,MUL_Y)  (MUL_X*MUL_Y)%MOD;
#define LCM(LCM_X,LCM_Y) (LCM_X*LCM_Y)/__gcd(LCM_X,LCM_Y);
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
int dx[]= {1,0,-1,0,1,-1,1,-1};
int dy[]= {0,1,0,-1,1,-1,-1,1};
ll cost[MAX];
vector<int>graph[MAX];
void dfs(int src,int par)
{
    for(auto i:graph[src])
    {
        if(i==par)
            continue;
        cost[i]+=cost[src];
        dfs(i,src);
    }
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        cost[a]+=b;
    }
    dfs(1,0);
    for(int i=1; i<=n; i++)
        cout<<cost[i]<<" ";


    return 0;
}
