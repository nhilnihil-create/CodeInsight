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
    ll n, k, rr, ss, pp;
    cin>>n>>k>>rr>>ss>>pp;
    string str;
    cin>>str;
    vl a(n);
    if(str[0]=='r')
    	a[0]=pp;
    else if(str[0]=='p')
    	a[0]=ss;
    else
    	a[0]=rr;
    vector<bool> fuck(k, true);
    forr1(i, n-1)
    {
    	if(i<k)
    	{
    		if(str[i]=='r')
		    	a[i]+=(pp+a[i-1]);
		    else if(str[i]=='p')
		    	a[i]+=(ss+a[i-1]);
		    else
		    	a[i]+=(rr+a[i-1]);
    	}
    	else
    	{
    		if(str[i]=='r')
		    {
		    	if(str[i-k]=='r')
		    	{
		    		if(fuck[i%k]==true)
		    			a[i]=a[i-1], fuck[i%k]=false;
		    		else 
		    		{
		    			fuck[i%k]=true;
		    			a[i]+=pp+a[i-1];
		    		}
		    	}
		    	else
		    	{
		    		a[i]+=(pp+a[i-1]);
		    		fuck[i%k]=true;
		    	}
		    }
		    else if(str[i]=='p')
		    {
		    	if(str[i-k]=='p')
		    	{
		    		if(fuck[i%k]==true)
		    			a[i]=a[i-1], fuck[i%k]=false;
		    		else 
		    		{
		    			fuck[i%k]=true;
		    			a[i]+=ss+a[i-1];
		    		}
		    	}
		    	else
		    	{
		    		a[i]+=(ss+a[i-1]);
		    		fuck[i%k]=true;
		    	}
		    }
		    else
		    {
		    	if(str[i-k]=='s')
		    	{
		    		if(fuck[i%k]==true)
		    			a[i]=a[i-1], fuck[i%k]=false;
		    		else 
		    		{
		    			fuck[i%k]=true;
		    			a[i]+=(rr+a[i-1]);
		    		}
		    	}
		    	else
		    	{
		    		a[i]+=(rr+a[i-1]);
		    		fuck[i%k]=true;
		    	}
		    }	
    	}
    }
    /*forr(i, n)
    	cout<<a[i]<<' ';*/
    cout<<a[n-1]<<endl;
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