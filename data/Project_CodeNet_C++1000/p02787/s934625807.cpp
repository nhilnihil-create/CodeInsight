#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll          long long
#define pb          push_back
#define INF         9223372036854775807ll
#define    endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        100000000000007ll
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define lower(u)    transform(u.begin(), u.end(), u.begin(), ::tolower);//convert string u to lowercase;
#define upper(u)    transform(u.begin(), u.end(), u.begin(), ::toupper);
using namespace std;

using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define N  10005
ll dp[10001][1001];
ll h,n;
ll A[N],B[N];
ll dps(ll hel,ll ind)
{
    if(hel<0)
        return 0;
    if(ind==0&&hel!=0)
    {
        return hell;
    }
    if(dp[hel][ind]!=-1)
        return dp[hel][ind];
    if(hel==0)
    {
        return dp[hel][ind]=0;    
    }
    vi v;
    v.pb(dps(hel-A[ind-1],ind-1)+B[ind-1]);
    v.pb(dps(hel,ind-1));
    // v.pb(dps(hel,ind-1));
    v.pb(dps(hel-A[ind-1],ind)+B[ind-1]);
    sort(all(v));

    dp[hel][ind]=v[0];
    return dp[hel][ind];
}
void solve()
{
    cin>>h>>n;
    rep(i,0,n)
    {
        cin>>A[i]>>B[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<dps(h,n)<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int TESTS=1;
//    cin>>TESTS;
    while(TESTS--)
    {
        solve();
    }
    return 0;
}