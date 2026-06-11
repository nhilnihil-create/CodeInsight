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
    ll n, k;
    cin>>n>>k;
    vl a(n);
    forr(i, n)
    {
    	cin>>a[i];
    	a[i]--;
    	a[i]%=k;
    }
    ll currsum=0, ans=0;
    map<ll, ll> mp1, mp2;
    forr(i, n)
    {
    	currsum+=a[i];
    	if(i>=k-1)
    	{
    		ll num=mp2[i-k];
    		mp1[num]--;
    		if(mp1[num]==0)
    			mp1.erase(num);
    	}
    	currsum%=k;
    	if(currsum==0)
    		ans++;
    	if(mp1.find(currsum)!=mp1.end())
    	{
    		ans+=mp1[currsum];
    	}
    	mp1[currsum]++;
    	mp2[i]=currsum;
    }
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