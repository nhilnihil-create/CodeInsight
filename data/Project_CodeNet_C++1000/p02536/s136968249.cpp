///...................SUBHASHIS MOLLICK...................///
///.....DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING....///
///.............ISLAMIC UNIVERSITY,BANGLADESH.............///
///....................SESSION-(14-15)....................///
#include<bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define pf(a) printf("%d",a)
#define pf2(a,b) printf("%d %d",a,b)
#define pf3(a,b,c) printf("%d %d %d",a,b,c)
#define sfl(a) scanf("%lld",&a)
#define sfl2(a,b) scanf("%lld %lld",&a,&b)
#define sfl3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define pfl(a) printf("%lld",a)
#define pfl2(a,b) printf("%lld %lld",a,b)
#define pfl3(a,b,c) printf("%lld %lld %lld",a,b,c)
#define nl printf("\n")
#define   timesave              ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define MPI map<int,int>mp;
#define fr(i,n) for(i=0;i<n;i++)
#define fr1(i,n) for(i=1;i<=n;i++)
#define frl(i,a,b) for(i=a;i<=b;i++)
#define tz 100000
#define clr0(a) memset(a,0,sizeof(a))
#define clr1(a) memset(a,-1,sizeof(a))
#define space " "
/*primes in range 1 - n
1 - 100(1e2) -> 25 pimes
1 - 1000(1e3) -> 168 primes
1 - 10000(1e4) -> 1229 primes
1 - 100000(1e5) -> 9592 primes
1 - 1000000(1e6) -> 78498 primes
1 - 10000000(1e7) -> 664579 primes
large primes ->
104729 1299709 15485863 179424673 2147483647 32416190071 112272535095293 48112959837082048697
*/
//freopen("Input.txt","r",stdin);
//freopen("Output.txt","w",stdout);
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
vector<int>vec[100005];
int vis[100005];
void dfs(int src)
{
    if(vis[src])
        return;
    vis[src]=1;
    for(int j=0;j<vec[src].size();j++)
    {
        int v=vec[src][j];
        if(vis[v]==0)
            dfs(v);
    }
}
main()
{
    timesave;
    int n,m,i,u,v,cnt=0;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt-1<<endl;
}

