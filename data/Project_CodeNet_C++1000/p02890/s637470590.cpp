#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
#define repf(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define mp make_pair
#define all(v) v.begin(),v.end()
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

ll power(ll a, ll n)
{
    ll ans=1;
    while(n)
    {
        if(n&1) ans*=a;
        a*=a;
        n>>=1;
    }
    return ans;
}

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int main()
{
    IOS;
    ll n;
    cin>>n;
    ll a[n+1]={0};
    repf(i,0,n)
    {
        ll x;
        cin>>x;
        a[x]++;
    }
    vector<ll> v,c;
    repf(i,1,n+1) if(a[i]) v.pb(a[i]);
    sort(all(v));
    c.pb(v[0]);
    repf(i,1,v.size()) 
    {
        c.pb(c[c.size()-1]+v[i]);
        // cout<<i<<endl;
    }
    repf(i,1,n+1)
    {
        ll lo=0,hi=n/i,ans=0,mid;
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            // if(mid==0) cout<<lo<<" "<<hi<<" "<<mid<<endl;
            // if(i==n) cout<<lo<<" "<<hi<<" "<<mid<<endl;
            int x=lower_bound(all(v),mid)-v.begin();
            ll val=v.size()-x;
            // if(i==n) cout<<val<<endl;
            if(x!=0) val+=c[x-1]/mid;
            if(val>=i) 
            {
                ans=max(ans,mid);
                lo=mid+1;
            }
            else hi=mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;  
}