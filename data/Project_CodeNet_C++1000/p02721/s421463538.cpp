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
    ll n, k, c;
    cin>>n>>k>>c;
    string s;
    cin>>s;
    vl l, r;
    ll cur=0;
    forr(i, k)
    {
        while(s[cur]=='x')
        cur++;
        l.pb(cur), cur++;
        forr(j, c)
        cur++;
    }
    cur=0;
    reverse(all(s));
    forr(i, k)
    {
        while(s[cur]=='x')
        cur++;
        r.pb(n-1-cur), cur++;
        forr(j, c)
        cur++;
    }
    sort(all(r));
  
    forr(i, k)
    {
        if(l[i]==r[i])
        cout<<l[i]+1<<endl;
    }
}
int main()
{
    ll test=1;
    //cin>>test;
    while(test--)
        solve();
}
