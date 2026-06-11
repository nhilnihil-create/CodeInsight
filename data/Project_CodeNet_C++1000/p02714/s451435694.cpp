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
    ll n; string str;
    ll ans=0, red=0, green=0;
    cin>>n>>str;
    n=str.length();
    forr(i, n)
    {
        if(str[i]=='R')
            red++;
        if(str[i]=='G')
            green++;
    }
    ll blue=n-(red+green);
    ans=blue*red*green;
    map<pair<ll, ll>, ll> mp1;
    for(ll i=0; i<n; i++)
    {
        for(ll j=i+1; j<n; j++)
        {
            ll k=2*j-i;
            vl a(3);
            a[0]=i;
            a[1]=j;
            a[2]=k;
            sort(all(a));
            pair<ll, ll> p1=mp(a[0], a[1]);
            if(a[2]>=n)
            continue;
            if(str[i]!=str[j]&&str[i]!=str[k]&&str[j]!=str[k])
            {
                ans--;
                //cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<str[i]<<" "<<str[j]<<" "<<str[k]<<" "<<endl;
                mp1[p1]++;
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