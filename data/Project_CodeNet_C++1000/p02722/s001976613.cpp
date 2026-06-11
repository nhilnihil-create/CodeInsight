#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

#define endl '\n'
#define ff first
#define ss second
#define sz(v) (int)v.size()
#define int long long
#define pb push_back
#define f(i,l,r) for(ll i=l;i<=r;i++)
#define rf(i,r,l) for(ll i=r;i>=l;i--)
#define Max 5000001
#define inf 2147483647
#define llinf 9223372036854775807
#define all(v) v.begin(),v.end()
#define bp(n) __builtin_popcountll(n)
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

#define d0(a) cout<<a<<' ';
#define d1(a) cout<<a<<endl;
#define d2(a,b) cout<<a<<' '<<b<<endl;
#define d3(a,b,c) cout<<a<<' '<<b<<' '<<c<<endl;
#define d4(a,b,c,d) cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
#define d5(a,b,c,d,e) cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<endl;
#define d6(a,b,c,d,e,f) cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<' '<<f<<endl;

const ll N=1e5+5,mod=1e9+7,bit=20;

//If divides N then remove all the powers of that divisor
//If not then rem = 1 + k*x , divisors of rem

set<ll> ans,d,dn;

signed main()
{
    fast;

    ll t=1;
    //cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        f(i,1,sqrt(n))
        {
            if(n%i==0)
            {
                d.insert(i);
                d.insert(n/i);
            }
        }
        d.erase(1);
        for(auto x:d)
        {
            ll curr=n;
            while(curr%x==0)
            {
                curr/=x;
            }
            if((curr-1)%x==0)
            {
                ans.insert(x);
            }
        }
        ll nn=n;
        n--;
        f(i,1,sqrt(n))
        {
            if(n%i==0)
            {
                dn.insert(i);
                dn.insert(n/i);
            }
        }
        dn.erase(1);
        n=nn;
        for(auto x:dn)
        {
            if(d.find(x)==d.end())
            {
                ans.insert(x);
            }
        }
        d1((int)ans.size());
    }
    return 0;
}
















