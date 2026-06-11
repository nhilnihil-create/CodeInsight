/*Ankon Ghosh
  KUET,ECE 2K16*/
#include<bits/stdc++.h>
/*#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
///#include <ext/pb_ds/detail/standard_policies.hpp>*/
///using namespace __gnu_pbds;
using namespace std;
using ll=long long;
#define inf 1e16
#define MAX 100005
#define mod 998244353
#define sf(a) scanf("%lld",&a)
#define sff(a,b) scanf("%lld %lld",&a,&b)
#define sfff(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define Case(i) printf("Case %lld: ",i)
#define setpre(number) cout<<fixed<<setprecision(10)<<number<<endl
#define pf(a) printf("%lld ",a)
#define pff(a,b) printf("%lld %lld\n",a,b)
#define FOR(i,n) for(ll i=0;i<n;i++)
#define FOR1(i,n) for(ll i=1;i<=n;i++)
#define LOOP(x,y) for(ll i=x;i<=y;i++)
#define RFOR(i,n) for(ll i=n-1;i>=0;i--)
#define RFOR1(i,n) for(ll i=n;i>0;i--)
#define RLOOP(x,y) for(ll i=y;i>=x;i--)
#define m_p make_pair
#define ff first
#define ss second
#define p_b push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define output freopen("output.txt","w",stdout)
map<ll,ll>mp1,mp;
vector<pair<ll,pair<ll,ll> > >vpp1;
vector<pair<ll,ll> >v,vpp,vp1;
vector<ll>v1,v2,fin;
map<pair<ll,ll>,bool>mbb;
map<ll,bool>mb,mb1;
ll a,b,c,n,d,e,f,ta,sum=0,cnt=0,m,l,req,sz,maxi,k;
priority_queue<ll>pq;
string str;
ll table[6100+10][6100+10];
ll arr[100+10];
void calc()
{
    memset(arr,0,sizeof arr);
    arr[3]=1;
    arr[4]=2;
    for(ll i=5; i<=100; i++)
    {
        if(i%2==1)
            arr[i]=arr[i-1]+2;
        else
            arr[i]=arr[i-1]+1;
    }
}
int main()
{
    fast;
    cin>>n>>k;
    for(ll i=2; i<=n; i++)
    {
        v.p_b({1LL,i});
    }
    ll x=n-2;
    ll tot=((x)*(x+1))/2;
    if(k>tot)
    {
        cout<<-1<<endl;
        return 0;
    }

    for(ll i=2; i<n; i++)
    {
        for(ll j=i+1; j<=n; j++)
        {
            if(tot!=k)
            {
                v.p_b({i,j});
                tot--;
            }
        }
    }
    ll l=v.size();
    cout<<l<<endl;
    for(ll i=0; i<l; i++)
        cout<<v[i].ff<<" "<<v[i].ss<<endl;
    return 0;
}