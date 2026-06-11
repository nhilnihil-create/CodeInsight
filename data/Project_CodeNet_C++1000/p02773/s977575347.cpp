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
    ll n;
    cin>>n;
    map<string, ll> mp1;
    ll maxm=0;
    forr(i, n)
    {
        string str;
        cin>>str;
        mp1[str]++;
        maxm=max(maxm, mp1[str]);
    }
    map<string, ll>:: iterator itr;
    vector<string> ans;
    for(itr=mp1.begin(); itr!=mp1.end(); itr++)
    {
        if(itr->second==maxm)
        ans.pb(itr->first);
    }
    sort(all(ans));
    forr(i, ans.size())
    cout<<ans[i]<<endl;
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