#include<bits/stdc++.h>
#include<cmath>
#define pb push_back
#define ld long double
#define mp make_pair
#define vl vector<ll> 
#define vd vector<double>
#define vld vector<long double>
#define ll long long int
#define pl pair<ll, ll>
#define all(a) a.begin(), a.end()
#define forr(i, n) for(ll i=0; i<n; i++) 
#define forr1(i, n) for(ll i=1; i<=n; i++)
using namespace std;
const ld PI =3.1415926535897923846;
const ll MOD = 1e9+7;
const ll N=998244353;
ll power(ll x,ll n){ll res=1;while(n>0){if(n&1) res=res*x%MOD;x=x*x%MOD;n>>=1;}return res;}
ll modinverse(ll a){return power(a, MOD-2);}
vl adj[200010];
void solve()
{
    bool check=true;
    ll n;
    cin>>n;
    forr(i, n)
    {
        ll x;
        cin>>x;
        if(x%2==0)
        {
            if(x%3!=0&&x%5!=0)
            {
                check=false;
                break;
            }
        }
    }
    if(check)
    cout<<"APPROVED";
    else
    cout<<"DENIED";
}
int main()
{
    ll test=1;
    //cin>>test;
    while(test--)
    {
        solve();
    }
}