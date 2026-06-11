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
    ll n, r;
    cin>>n>>r;
    if(n<10)
    {
        cout<<100*(10-n)+r;
    }
    else
    cout<<r;
}
int main()
{
    ll test=1;
    //cin>>test;
    while(test--)
        solve();
}