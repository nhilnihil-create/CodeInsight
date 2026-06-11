#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;

#define ll long long int
#define pb push_back
#define RONALDO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<ll, ll>
#define ff first
#define ss second
#define mod 1000000007
#define vi vector<ll>
#define mi map<ll, ll>
#define Max(x, y, z) max(x, max(y, z))
#define Min(x, y, z) min(x, min(y, z))

//LOVE U MESSI && CRistiano !!

//INSPIRATIONAL MICHAEL PHELPS && USAIN BOLT !!

int main(){
RONALDO;
ll n,f=0;
cin >> n;
vector<pair<ll,ll>> v;
for (ll i = 0;i<n;i++)
{
    ll x,y;
    cin >> x >> y;
    v.pb({x, y});
}
for (ll i = 0;i<n-2;i++)
{
    if(v[i].first==v[i].second && v[i+1].first==v[i+1].second && v[i+2].first==v[i+2].second)
        f = 1;
}
if(f){
        cout<<"Yes\n";
    }else
        cout<<"No\n";
return 0;
}