#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define mod 1000000007
#define inf 1e18+42
#define endl "\n"

#define out1(a) cout<<#a<<" "<<a<<endl
#define out2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define out3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
#define fori(it,A) for(auto it=A.begin();it!=A.end();it++)

#define ft first
#define sd second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define zero(x) memset(x,0,sizeof(x));
 
using namespace std;

int binpow(int,int);
void dfs( vector< vector<int> >&, int , vector<int>& );
void bfs( vector< vector<int> >&, int , vector<int>& );

void solve()
{
    int n;
    cin>>n;

    vector<int> a(n);

    rep(i,0,a.size())
    {
        cin>>a[i];
    }

    int dp[n+1][n+1];
    zero(dp);
    vector< pair<int,int> > s;

    rep(i,0,a.size())
    {
        s.pb(mp(a[i],i));
    }

    sort(all(s));

    int ans = 0;

    repr(len,n,1)
    {
        rep(st,0,n-len+1)
        {
            if ( len == 1 )
            {
                ans = max(dp[st][st]+s[len-1].ft*abs(s[len-1].sd-st),ans);
                continue;
            }
            dp[st][st+len-2] = max(dp[st][st+len-2],dp[st][st+len-1]+(s[len-1].ft*abs(s[len-1].sd-(st+len-1))));
            dp[st+1][st+len-1] = max(dp[st+1][st+len-1],dp[st][st+len-1]+(s[len-1].ft*abs(s[len-1].sd-(st))));
        }
    }

    cout<<ans<<endl;
}

signed main()
{
    fast;
    int t = 1;
    // cin>>t;

    while(t--)
    {
        solve();
    }
    return 0;
}

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void dfs ( vector< vector<int> > &v , int x , vector<int> &vis )
{
    vis[x] = 1;

    rep(i,0,v[x].size())
    {
        if( vis[v[x][i]] == 0 )
        {
            dfs(v,v[x][i],vis);
        }
    }
}

void bfs( vector< vector<int> > &v , int x , vector<int> &vis )
{
    queue<int> q;
    q.push(x);

    while( !q.empty() )
    {
        int p = q.front();
        q.pop();

        rep(i,0,v[p].size())
        {
            if ( vis[v[p][i]] == 0 )
            {
                vis[v[p][i]] = 1;
                q.push(v[p][i]);
            }
        }
    }
}