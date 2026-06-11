#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds; 

#define int long long
#define pb push_back
#define pf push_front
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f first
#define s second
#define sz(x) (int)x.size()
#define endl "\n"
#define forn(i,n) for(int i=0;i<n;++i)
#define fore(i,l,r) for(int i=int(l);i<=int(r);++i)
#define rep(i,begin,end) for(__typeof(end) i=(begin);i!=(end);i++)
#define fill(a,value) memset(a,value,sizeof(a));
#define gcd(a,b) __gcd((a),(b))
#define watch1(x) cout<<(x)<<endl
#define watch2(x,y) cout<<(x)<<" "<<(y)<<endl
#define watch3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef long double ld; 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;

const int INF = 9e18;
const int mod = 1e9 + 7;
const int M = 1005;
const int N = 13;

int i,j,n,m,a[M],b[M],dp[1<<N];
set<int> key[M];

void solve()
{
    cin>>n>>m;
    for(i=1;i<=m;++i)
    {
        cin>>a[i]>>b[i];
        for(j=1;j<=b[i];++j)
        {
            int x;
            cin>>x;
            key[i].insert(x-1);
        }
    }
    for(i=0;i<(1<<n);++i)
    {
        dp[i]=INF;
    }
    dp[0]=0;
    for(i=1;i<=m;++i)
    {
        for(j=0;j<(1<<n);++j)
        {
            int box=0;
            for(int k:key[i])
            {
                box|=(1<<k);
            }
            int mask=j;
            dp[mask|box]=min(dp[mask|box],dp[mask]+a[i]);
        }
    }
    if(dp[(1<<n)-1]==INF)
        dp[(1<<n)-1]=-1;
    cout<<dp[(1<<n)-1];
}

signed main()
{
    fastio;
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}