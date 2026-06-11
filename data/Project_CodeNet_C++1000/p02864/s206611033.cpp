#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int sll;
typedef  double ld;
#define A 1000000007ll
#define D 1000000000ll
#define B 998244353ll
#define C 1000000000000000000ll
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oset tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update> 
#define pb push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define ve vector
#define br break
#define PI 3.14159265358979323
#define subt cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n"
 
ll dp[305][305];

int main() 
{
    FAST;
    ll n,k;
    cin>>n>>k;
    ll a[n+1];
    a[0]=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<305;i++)
        for(int j=0;j<305;j++)
            dp[i][j]=C;
    dp[0][0]=0;
    dp[1][0]=a[1];
    for(int i=2;i<=n;i++)
        for(int j=0;j<i;j++)
            for(int p=i-1;p>=i-j-1;p--)
                if(dp[p][p-i+1+j]!=C)
                    dp[i][j]=min(dp[i][j],dp[p][p-i+1+j]+max(0ll,a[i]-a[p]));
    ll ans=C;
    for(int i=n;i>=n-k;i--)
        ans=min(ans,dp[i][k+i-n]);
    cout<<ans;
    subt;
    return 0;
}