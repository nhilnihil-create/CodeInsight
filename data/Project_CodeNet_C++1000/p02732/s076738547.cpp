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
void solve()
{
    ll n;
    cin>>n;
    vl a(n);
    map<ll, ll> mp1;
    ll prod=0;
    forr(i, n)
    {
        cin>>a[i];
        mp1[a[i]]++;
    }
    map<ll, ll>:: iterator itr;
    for(itr=mp1.begin(); itr!=mp1.end(); itr++)
    {
        ll x=itr->second;
        prod+=x*(x-1)/2;
    }
    for(ll i=0; i<n; i++)
    {
        ll num=mp1[a[i]];
        ll prod2=prod;
        prod2-=(num*(num-1))/2;
        num--;
        prod2+=(num*(num-1))/2;
        cout<<prod2<<endl;
    }
}
int main()
{
    ll test=1;
    //cin>>test;
    while(test--)
        solve();
}