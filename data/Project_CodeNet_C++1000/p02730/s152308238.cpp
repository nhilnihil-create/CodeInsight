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
bool isPal(string s)
{
    string t=s;
    reverse(all(t));
    return t==s;
}
void solve()
{
    string s;
    cin>>s;
    ll n=s.length();
    bool val= isPal(s.substr(0,(n-1)/2));
    //cout<<val;
    val=val&&isPal(s.substr((n+3)/2-1, n+1-(n+1)/2));
    val=val&&isPal(s);
    if(val)
    cout<<"Yes";
    else
    cout<<"No";
}
int main()
{
    ll test=1;
    //cin>>test;
    while(test--)
        solve();
}