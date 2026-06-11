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
    ll n, p;
    cin>>n>>p;
    string str;
    cin>>str;
    vl a(p);
    a[0]++;
    ll pow_of_ten=1;
    ll suff=0;
    ll ans=0;
    if(p==2)
    {
        forr(i, n)
        {
            ll dig=str[i]-'0';
            if(dig%2==0)
            {
                ans+=(i+1);
            }
        }
        cout<<ans;
        return;
    }
    if(p==5)
    {
        forr(i, n)
        {
            ll dig=str[i]-'0';
            if(dig%5==0)
            {
                ans+=(i+1);
            }
        }
        cout<<ans;
        return;
    }
    for(ll i=n-1; i>=0; i--)
    {
        ll dig=str[i]-'0';
        suff=((dig*pow_of_ten)+suff)%p;
        pow_of_ten=pow_of_ten*10%p;
        ans+=a[suff];
        a[suff]++;
    }
    //for(ll i=0; i<n; i++)
    cout<<ans;
}
int main()
{
    ll test=1;
    //cin>>test;
    while(test--)
        solve();
}