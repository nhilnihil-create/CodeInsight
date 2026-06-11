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
const ll MOD = 1000000007;
const ll N=998244353;
ll power(ll x,ll n){ll res=1;while(n>0){if(n&1) res=res*x%MOD;x=x*x%MOD;n>>=1;}return res;}
ll modinverse(ll a){return power(a, MOD-2);}
void solve()
{
    ll x, y;
    cin>>x>>y;
    if((2*x-y)%3)
    {
    	cout<<0<<endl;
    	return;
    }
    ll second=(2*x-y)/3;
    if((y-second)%2)
    {
    	cout<<0<<endl;
    	return;
    }
    ll first=(y-second)/2;
    if(second<0||first<0)
    {
    	cout<<0<<endl;
    	return;
    }
    ll fact1=1, fact2=1, fact3=1;
    forr1(i, first)
    {
    	fact1*=i;
    	fact1%=MOD;
    }
    forr1(i, second)
    {
    	fact2*=i;
    	fact2%=MOD;
    }
    forr1(i, first+second)
    {
    	fact3*=i;
    	fact3%=MOD;
    }
    ll ans=(fact3*modinverse(fact2))%MOD;
    ans%=MOD;
    ans*=modinverse(fact1)%MOD;
    ans%=MOD;
    cout<<ans<<endl;
}
int main()
{
	#ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test=1;
    //cin>>test;
    while(test--)
    {
        solve();
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}