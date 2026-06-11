#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define PI acos(-1)
#define bp __builtin_popcountll
#define all(x) x.begin(),x.end()
#define sp fixed<<setprecision
#define pii pair<long long,long long>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int MOD = (1e9)+7;
const int N = 3005;

int n,t,dp[N][N];
pii a[N];

int rec(int i,int t)
{
    if(i == n)return 0;
    if(t<=0)return 0;
    if(dp[i][t]!=-1)return dp[i][t];
    dp[i][t] = max(rec(i+1,t),a[i].ss+rec(i+1,t-a[i].ff));
    return dp[i][t];
}

signed main()
{
    FAST
    int tc=1;
    //cin>>tc;
    for(int ti=1;ti<=tc;ti++)
    {
        memset(dp,-1,sizeof(dp));
        cin>>n>>t;
        for(int i=0;i<n;i++)cin>>a[i].ff>>a[i].ss;
        sort(a,a+n);
        cout<<rec(0,t)<<endl;
    }
    return 0;
}
