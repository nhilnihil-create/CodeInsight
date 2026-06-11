//agrawal117
//chahatagrawal117
#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
typedef long long int ll;
using namespace std;
#define MAX 2005
const ll oo=1000000007;
vector<pair<ll,ll>> v;
ll dp[MAX][MAX];
ll n;
ll solve(int l, int r)
{
    if(r<l) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    int i=n-(r-l+1)+1;
    ll x= v[i].first*abs(l-v[i].second) + solve(l+1,r);
    ll y= v[i].first*abs(r-v[i].second) + solve(l,r-1);
    dp[l][r]=max(x,y);
    return dp[l][r];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    v.push_back({oo,0});
    for(int i=1;i<=n;i++){
        ll a; cin>>a;
        v.push_back({a,i});
    }
    sort(v.rbegin(),v.rend());
    memset(dp,-1,sizeof(dp));
    cout<<solve(1,n);
}