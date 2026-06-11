#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0)
#define endl "\n";
#define pb push_back
#define f first
#define s second
#define all(a) a.begin(),a.end()
#define int long long
const int MOD=1e9+7;
const int N=2e3+10;
int dp[N][N];
vector<pair<int,int> >v;
int go(int pos,int l,int r)
{
    if(pos==v.size())
    {
        return 0;
    }
    int &ans=dp[l][r];
    if(ans!=-1)
        return ans;
    ans=0;
    ans=max(ans,go(pos+1,l+1,r)+v[pos].f*abs(v[pos].s-l));
    ans=max(ans,go(pos+1,l,r-1)+v[pos].f*abs(v[pos].s-r));
    return ans;

}
int32_t main()
{
    IOS;
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        v.pb({x,i});
    }
    sort(all(v));
    reverse(all(v));
    cout<<go(0,1,n)<<endl;  
}