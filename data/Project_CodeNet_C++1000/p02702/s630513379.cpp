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
void solve()
{
    string str;
    cin>>str;
    ll n=str.length();
    ll num=2019;
    vl a(num);
    ll ans=0;
    ll pow_of_ten=1;
    ll suf=0;
    a[0]++;
    for(ll i=n-1; i>=0; i--)
    {
        ll dig=str[i]-'0';
        suf=((dig*pow_of_ten)+suf)%num;
        pow_of_ten=pow_of_ten*10%num;
        ans+=a[suf];
        a[suf]++;
    }
    cout<<ans;
}
int main()
{
    ll test=1;
    //cin>>test;
    while(test--)
        solve();
}