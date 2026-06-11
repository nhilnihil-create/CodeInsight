#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define ff first
#define ss second
//#define p pair<ll,ll>
#define pb push_back
#define endl '\n'
#define w(t) ll test;cin>>test;while(test--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define iof  freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define pi acos(-1)
const int mxn=1e9+5;
int main()
{
    fast;
    ll n,k;
    cin>>n>>k;
    vector<ll>p(n);
    vector<ll>cost(n);
    for(auto &i:p)
    {
        cin>>i;
        i--;
    }
    for(auto &i:cost)
    {
        cin>>i;
    }
   // vector<int>visited(n);
   ll mx=-1e18-5;
   ll ans=-1e18-5;
    for(ll i=0;i<n;i++)
    {
        vector<ll>vec;
        ll sum=0;
        ll x=i;
        while(true)
        {
            x=p[x];
            sum+=cost[x];
            vec.pb(sum);
            if(x==i)break;
        }
        ll loop=k/vec.size();
        ll r=k%vec.size();
        if(vec.back()>0&&k>vec.size())
        {
            ll mx1=-1e18-5;
            for(auto i:vec)
            {
                mx1=max(mx1,i);
            }
            ans=max(ans,(loop-1)*vec.back()+mx1);
            mx1=-1e9-5;
            for(int i=0;i<(ll)r;i++)
            {
                mx1=max(mx1,vec[i]);
            }
            ans=max(ans,loop*vec.back()+mx1);
        }
        else
        {
            for(int i=0;i<(ll)min((ll)vec.size(),k);i++)
            {
                ans=max(ans,vec[i]);
            }
        }
    }
    cout<<ans<<endl;
}

