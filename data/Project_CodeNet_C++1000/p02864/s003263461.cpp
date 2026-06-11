// #pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define N 1000000007
#define N2 998244353
#define Nmax 100001
#define INF (ll)1e18
#define pll pair<ll,ll>
#define pii pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(ll i=m;i<(n);i++)
#define get(n) ll (n); scanf("%lld",&(n));
#define get2(n,k) ll (n),(k); scanf("%lld%lld",&(n),&(k));
#define get3(n,m,k) ll (n),(m),(k); scanf("%lld%lld%lld",&(n),&(m),&(k));
#define gets(s) string (s); cin >> (s);
#define ALL(c) (c).begin(),(c).end()
#define fill_nums(A,n) vector<ll> A((n)); for(ll i=0;i<n;i++) scanf("%lld",&A[i]);
#define fill_edges(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1); adj[b-1].pb(a-1);}
#define fill_direct(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1);}
#define pi 3.1415926535897



int main() {

    get2(n,k);
    fill_nums(A,n);

    if(k>=n) {
        printf("0\n");
        return 0;
    }

    vector<vector<ll>> dp(n-k+1, vector<ll>(n+1,INF));
    dp[0][0] = 0;

    for(int i=1;i<=n-k;i++) {
        for(int j=1;j<=n;j++) {
            for(int k=0;k<j;k++) {
                dp[i][j] = min(dp[i][j], dp[i-1][k] + max((ll)0, (A[j-1]-(k-1>=0 ? A[k-1] : 0))));
            }
        }
    }

    ll res = INF;
    for(int j=1;j<=n;j++)
        res = min(res, dp[n-k][j]);
    printf("%lld\n", res);

    return 0;  
}