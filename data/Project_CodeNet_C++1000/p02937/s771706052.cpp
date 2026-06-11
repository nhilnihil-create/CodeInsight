#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define frw(i, a, b) for(int i = a; i < b; i++)
#define fi first
#define se second
#define pb push_back
#define in insert
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) int(a.size())
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<ll, ll>
#define plll pair<ll, pll>
#define vpii vector<pii>
#define vpiii vector<piii>
#define vpll vector<pll>
#define vplll vector<plll>
#define mod 1000000007

int modInverse(ll a, ll m) 
{ 
    ll m0 = m; 
    ll y = 0, x = 1; 
    if (m == 1) 
      return 0; 
    while (a > 1) 
    { 
        ll q = a / m; 
        ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) 
       x += m0; 
    return x; 
} 


int main() {
   string s,u;
   cin>>s>>u;
   vector<ll> l[28];
   
   for(int i=0;i<s.length();i++)
   {
   		l[s[i]-'a'].push_back(i+1);
   }
   ll r=-1;
   ll ans=0;
   ll cnt=0;
   for(int i=0;i<u.length();i++)
   {

   		ll z=l[u[i]-'a'].size();
   		if(z==0)
   		{	ans=mod;
   			break;
   		}
   		ll v=upper_bound(l[u[i]-'a'].begin(),l[u[i]-'a'].end(),r)-l[u[i]-'a'].begin();
   		if(v==l[u[i]-'a'].size())
   		{
   			r=l[u[i]-'a'][0];
   			cnt++;
   		}
   		else
   		{
   			r=l[u[i]-'a'][v];
   			
   		}
   		
   }

   if(ans==mod)
   	ans=-1;
   else{
   ans=cnt*s.length();
   
   ans+=r;
}
   
   cout<<ans;
}
