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
    int n,p;
    cin>>n>>p;

    string s;
    cin>>s;

    reverse(all(s));

    if ( p != 2 && p != 5 )
    {
        vector<int> count(p,0);
        int ans = 0;
        int x = 1;
        int t = 0;
        rep(i,0,s.length())
        {
            count[t]++;
            t += (s[i]-'0')*x;
            t %= p;
            ans += count[t];
            x = x*10 % p;
        }

        cout<<ans<<endl;
    }
    else
    {
        int ans = 0;
        rep(i,0,s.length())
        {
            int x = s[i]-'0';

            if ( x % p == 0 )
            {
                ans += (s.length()-i);
            }
        }

        cout<<ans<<endl;
    }
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