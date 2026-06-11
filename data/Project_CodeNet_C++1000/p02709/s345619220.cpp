#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
// #define LOCAL
const int MAXN=2e3+10;
int N;
vector<pair<ll,int>>A;
ll dp[MAXN][MAXN];
bool cmp(pair<ll,int>p1,pair<ll,int>p2)
{
    return p1.first>p2.first;
}
void solve()
{
    cin>>N;
    for(int u=1;u<=N;u++){
        ll t;
        cin>>t;
        A.push_back({t,u});
    }
    sort(A.begin(),A.end(),cmp);
    for(int u=1;u<=N;u++){
        for(int t=0;t<u;t++){
            int l=t;
            int r=u-1-l;
            ll v=A[u-1].first,p=A[u-1].second;
            dp[l+1][r]=max(dp[l+1][r],dp[l][r]+v*abs(l+1-p));
            dp[l][r+1]=max(dp[l][r+1],dp[l][r]+v*abs(N-r-p));
        }
    }
    ll ans=0;
    for(int v=0;v<=N;v++){
        ans=max(ans,dp[v][N-v]);
    }
    cout<<ans;
}
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    solve();
}