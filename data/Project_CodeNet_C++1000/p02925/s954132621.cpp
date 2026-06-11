/*!enjoy karo yaar!*/

//CF,CC,AtC,SPOJ: hp1999
//HE: hemant269
//HR: hemant2132

// ref: https://img.atcoder.jp/abc139/editorial.pdf
// crux: mapping the "matches" to a graph

// really nice problem!

#include<bits/stdc++.h>
using namespace std;

//#define     int             long long int
#define     fast()          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     all(x)          begin(x),end(x)
#define     rz(x)           resize(x)
#define     asn(x,y)        assign(x,y)
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     sz(x)           ((int)(x.size()))
#define     eb              emplace_back
#define     pb              push_back
#define     pf              push_front
#define     pob             pop_back
#define     pof             pop_front
#define     ins             insert
#define     vi              vector<int>
#define     pii             pair<int,int>
#define     mii             map<int,int>
#define     F               first
#define     S               second
#define     remax(a,b)      a=max(a,b)
#define     remin(a,b)      a=min(a,b)
#define     bitcount(x)     __builtin_popcountll(x)
#define     iceil(n,x)      (((n)-1)/(x)+1)
#define     dbug(x)         cout<<#x<<": "<<(x)<<"\n"
#define     flush           fflush(stdout)
#define     show(x)         for(auto zz:x)cout<<zz<<" ";cout<<"\n";
#define     show2(x)        for(auto zz:x)cout<<zz.F<<" "<<zz.S<<"\n";

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ld pi=acos(-1);
const ll inf=1e18,M=1e9+7;
const int N=1e3+5,NN=N*N;

vi v[NN],vis(NN),dist(NN),ind(NN);
int mat[N][N];

int n;

int getnode(int x,int y)
{
    if(x>y)
        swap(x,y);

    return ((x-1)*n+y);
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<n-1;++j)
            cin>>mat[i][j];
    }

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<n-1;++j)
        {
            int a=getnode(i,mat[i][j-1]);
            int b=getnode(i,mat[i][j]);
            v[a].pb(b);                         // req. condition for ordering the matches...
            ++ind[b];
        }
    }

    queue<int> qu;

    for(int i=1;i<=n;++i)
    {
        for(int j=i;j<=n;++j)
        {
            int x=getnode(i,j);
            if(sz(v[x]) && !ind[x])
                qu.push(x),vis[x]=1;
        }
    }

    int ans=0;
    while(!qu.empty())
    {
        auto x=qu.front();
        qu.pop();

        ans=max(ans,dist[x]);

        for(auto c:v[x])
        {
            if(vis[c])                      // detecting a cycle
            {
                cout<<-1;
                return;
            }

            --ind[c];
            if(!ind[c])
            {
                qu.push(c);
                vis[c]=1;
                dist[c]=dist[x]+1;
            }
        }
    }

    for(int i=1;i<=n*n;++i)
    {
        if(sz(v[i]) && ind[i])
        {
            cout<<-1;
            return;
        }
    }

    cout<<ans+1;
}

int32_t main()
{
    fast();

    int t=1;
    //cin>>t;
    for(int z=1;z<=t;++z)
    {
        solve();
        //cout<<"\n";
    }

    return 0;
}

