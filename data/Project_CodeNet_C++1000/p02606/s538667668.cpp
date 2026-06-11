#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
typedef long long int  ll;
#define loop() for(int i=0; i<(n); i++)
const ll MOD=998244353;
ll fast_exp(ll base, ll exp) 
{
    ll res=1;
    while(exp>0) 
    {
       if(exp%2==1) 
       	res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res%MOD;
}

ll gcdExtended(ll a, ll b, ll *x, ll *y);   

ll modInverse(ll b, ll m) 
{ 
    ll x, y; // used in extended GCD algorithm 
    ll g = gcdExtended(b, m, &x, &y); 
  
    // Return -1 if b and m are not co-prime 
    if (g != 1) 
        return -1; 
  
    // m is added to handle negative x 
    return (x%m + m) % m; 
} 
  
// Function to compute a/b under modlo m 
ll modDivide(ll a, ll b, ll m) 
{ 

    a = a % m; 
    ll inv = modInverse(b, m); 
    return (inv * a) % m; 
} 
  
// C function for extended Euclidean Algorithm (used to 
// find modular inverse. 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; // To store results of recursive call 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}
ll calc(ll diff,ll x)
{
	ll a=fast_exp(x,diff)-1;
	ll b=x-1;
	return modDivide(a,b,MOD);
}


void solve()
{
	//code	
	ll l,r,d;
	cin>>l>>r>>d;
	ll count=r/d-l/d;
	if(l%d==0)
		count++;
	cout<<count<<endl;
	
}


int main(){
	fast
	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
}