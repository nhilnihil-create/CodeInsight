#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds; 

#define int long long
#define pb push_back
#define pf push_front
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f first
#define s second
#define sz(x) (int)x.size()
#define endl "\n"
#define forn(i,n) for(int i=0;i<n;++i)
#define fore(i,l,r) for(int i=int(l);i<=int(r);++i)
#define rep(i,begin,end) for(__typeof(end) i=(begin);i!=(end);i++)
#define fill(a,value) memset(a,value,sizeof(a));
#define gcd(a,b) __gcd((a),(b))
#define watch1(x) cout<<(x)<<endl
#define watch2(x,y) cout<<(x)<<" "<<(y)<<endl
#define watch3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef long double ld; 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;

const int INF = 9e18;
const int mod = 1e9 + 7;
const int N = 505;

int n,k,a[N],change[N],sum=0;

bool check(int val)
{
    int nsum=0;
    for(int i=1;i<=n;++i)
    {
        if(a[i]%val==0)
        {
            change[i]=a[i];
            nsum+=change[i];
        }
        else
        {
            int x=a[i]/val;
            if(a[i]-x*val<(x+1)*val-a[i])
            {
                change[i]=x*val;
            }
            else
            {
                change[i]=(x+1)*val;
            }
            nsum+=change[i];
        }
    }
    if(nsum==sum)
    {
        int req=0;
        for(int i=1;i<=n;++i)
        {
            req+=abs(change[i]-a[i]);
        }
        return req/2<=k;
    }
    else if(nsum>sum)
    {
        int extra=(nsum-sum)/val,req=0;
        vi least;
        for(int i=1;i<=n;++i)
        {
            if(change[i]<=a[i])
            {
                req+=abs(a[i]-change[i]);
            }
            else
            {
                least.pb(a[i]-change[i]+val);
            }
        }
        sort(all(least));
        for(int i=0;i<sz(least);++i)
        {
            if(i<extra)
            {
                req+=least[i];
            }
            else
            {
                req+=abs(least[i]-val);
            }
        }
        return req/2<=k;
    }
    else
    {
        int extra=(sum-nsum)/val,req=0;
        vi least;
        for(int i=1;i<=n;++i)
        {
            if(change[i]>=a[i])
            {
                req+=abs(a[i]-change[i]);
            }
            else
            {
                least.pb(change[i]+val-a[i]);
            }
        }
        sort(all(least));
        for(int i=0;i<sz(least);++i)
        {
            if(i<extra)
            {
                req+=least[i];
            }
            else
            {
                req+=abs(least[i]-val);
            }
        }
        return req/2<=k;
    }
}

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int ans=0;
    for(int i=1;i*i<=sum;++i)
    {
        if(sum%i==0)
        {
            if(check(i))
                ans=max(ans,i);
            if(check(sum/i))
                ans=max(ans,sum/i);
        }
    }
    cout<<ans;
}

signed main()
{
    fastio;
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}