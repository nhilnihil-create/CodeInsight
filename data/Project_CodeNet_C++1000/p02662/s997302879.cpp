#include<bits/stdc++.h>
#define inf 2000000000
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define rng_23 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define mod 998244353
 using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int,int> mii;
int ara[3001];
ll dp[3001][3001];
int main()
{
    int i,j,k;
    int n,s;
    scanf("%d %d",&n,&s);
    for(i=1;i<=n;i++)
        scanf("%d",&ara[i]);
    dp[0][0]=1;
    for(i=1;i<=n;i++){
        for(j=0;j<=3000;j++)
            dp[i][j]=(2*dp[i-1][j]+((j>=ara[i])? dp[i-1][j-ara[i]]:0))%mod;
    }
    printf("%lld",dp[n][s]);
}
