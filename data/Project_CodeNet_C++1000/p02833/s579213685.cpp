#include<bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ll long long
#define ss second
#define ff first
#define pll pair<ll,ll>
#define vll vector<ll>
#define mll map<ll,ll>
#define mod 1000000007
#define w(x) ll x; cin>>x; while(x--)
#define ps(x,y) fixed<<setprecision(y)<<x;
#define fo(i, j, k, in) for (ll i=j ; i<k ; i+=in)
#define re(i, j) fo(i, 0, j, 1)
#define pi 3.1415926535897932384626433832795
#define all(cont) cont.begin(), cont.end()
#define countbit(x) __builtin_popcount(x)
#define mod 1000000007
#define lo lower_bound
#define de(n) ll n;cin>>n;
#define def(a,n) ll n;cin>>n;ll a[n];re(i,n){cin>>a[i];}
#define defi(a,n,k) ll n;cin>>n; ll k;cin>>k;ll a[n];re(i,n){cin>>a[i];}
#define deb(x) cout<<#x<<"="<<x<<endl;
#define tr(it,a) for(auto it=a.begin();it!=a.end();it++)
#define nl cout<<endl;
using namespace std;
void cp()
{
    ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0); 
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "r", stdin);  
    freopen("output.txt", "w", stdout);
#endif
}
ll digit(ll n)
{
    ll q=0;
    while(n>0)
    {
        q++;
        n/=10;
    }
    return q; 
}
int main()
{
    //cp();
    //w(x)
    {
        de(n);
        if(n%2==1)
        cout<<"0";
        else
        {
            ll k=digit(n);
            ll ni=n;
            ll ans=0;
            ll kk=5;
            while(kk<=ni)
            {
                ll ch=ni/kk;
                    ans+=(ch/2);
                kk*=5;
            }
            cout<<ans;
        }
        
    }
    return 0;
}