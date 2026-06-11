#include <bits/stdc++.h>

#define int long long
#define ci(m)     for(int i=0;i<m;i++)
#define cj(m)     for(int j=0;j<m;j++)
#define ck(m)     for(int k=0;k<m;k++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;
vector<int>v[2000];
int dp[2000][2000];
int32_t main() {
    nitin;
    int n,x,y;
    for(auto &a:dp) for(auto &b:a) b=INT_MAX;
    cin>>n>>x>>y;
    --x;
    --y;
    dp[0][0]=0;
    for(int i=1;i<n;i++)
    {
        dp[i][i]=0;
        v[i].push_back(i-1);
        v[i-1].push_back(i);
    }
    v[x].push_back(y);
    v[y].push_back(x);
    for(int i=0;i<n;i++)
    {
        queue<int>q;
        unordered_map<int,int>visited;
        int node=i;
        q.push(node);
        visited[i]=1;
        while(!q.empty())
        {
            int vert=q.front();
            q.pop();
            for(auto c:v[vert])
            {
                if(!visited[c])
                {
                    dp[node][c]=dp[node][vert]+1;
                    q.push(c);
                    visited[c]=1;
                }
            }
        }
    }
    vector<int>cnt(n+1,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cnt[dp[i][j]]++;
    }
    for(int i=1;i<=n-1;i++)
        cout<<cnt[i]/2<<endl;
    return 0;
}