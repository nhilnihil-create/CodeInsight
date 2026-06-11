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
double dist(ll x1, ll y1, ll x2, ll y2)
{
	return sqrt((1.0*x1-x2)*(1.0*x1-x2)+(1.0*y1-y2)*(1.0*y1-y2));
}
void solve()
{
    ll n;
    cin>>n;
    double ans=0;
    ll factn=1, factn_1=1;
    vector<pl> coo(n);
    forr(i, n)
    	cin>>coo[i].first>>coo[i].second;
    forr1(i, n)
    {
    	if(i!=n)
    		factn_1*=i;
    	factn*=i;
    }
    forr(i, n)
    {
    	for(ll j=i+1; j<n; j++)
    	{
    		ans+=dist(coo[i].first, coo[i].second, coo[j].first, coo[j].second);
    	}
    }
	std::cout<<setprecision(15)<<(2*factn_1*ans/factn)<<endl;
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