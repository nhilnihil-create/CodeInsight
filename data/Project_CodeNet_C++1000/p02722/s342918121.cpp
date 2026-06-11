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
    ll n;
    cin>>n;
    ll ans=0;
    for(ll i=1; i<=sqrt(n-1); i++)
    {
        if((n-1)%i==0)
        {
            if((n-1)/i!=i)
            ans++;
            ans++;
        }
    }
    ans--;
    for(ll i=1; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            ll temp=n;
            if(n/i!=i)
            {
                while(i!=1)
                {
                    if(temp%i==0)
                    temp/=i;
                    else break;
                }
                if(temp==1||temp%i==1)
                ans++;
                temp=n;
                while(1)
                {
                    if(temp%(n/i)==0)
                    temp/=(n/i);
                    else break;
                }
                if(temp==1||temp%i==1)
                ans++;
            }
            else
            {
                while(i!=1)
                {
                    if(temp%i==0)
                    temp/=i;
                    else break;
                }
                if(temp==1)
                ans++;
            }
        }
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
