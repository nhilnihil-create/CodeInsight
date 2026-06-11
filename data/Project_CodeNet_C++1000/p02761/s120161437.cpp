#include<bits/stdc++.h>
#include<cmath>
#define pb push_back
#define ld long double
#define mp make_pair
#define vl vector<ll> 
#define vd vector<double>
#define vld vector<long double>
#define ll int
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
    ll n, m;
    cin>>n>>m;
    map<ll, ll> mp1;
    vector<bool> check(n);
    forr(i, m)
    {
        ll place, dig;
        cin>>place>>dig;
        if(mp1.find(place)==mp1.end())
        {
            mp1[place]=dig;
            check[place-1]=true;
        }
        else
        {
            if(mp1[place]!=dig)
            {
                cout<<"-1";
                return;
            }
        }
        if(n!=1&&place==1&&dig==0)
        {
            cout<<"-1";
            return;
        }
    }
    if(n==1)
    {
        cout<<mp1[1];
        return;
    }
    forr1(i, n)
    {
        
        if(check[i-1]||i-1)
        cout<<mp1[i];
        else
        cout<<1;
    }
}
int main()
{
    ll test=1;
    //cin>>test;
    while(test--)
        solve();
}