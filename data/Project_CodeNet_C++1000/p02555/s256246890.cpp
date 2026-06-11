#include <bits/stdc++.h>
#define ll long long int
#define K 1000000007
//#define x first
//#define y second
using namespace std;
ll fact[2001];
ll invfact[2001];
ll power(ll x, ll y, ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 
ll inverseMod(ll a)
{
    return power(a,K-2,K);
}
ll c(ll n, ll r)
{
    if(n<r)return 0;
    if(n<0||r<0)return 0;
    ll ans= ( ( fact[n]* invfact[n-r])%K *invfact[r] )%K;
    return ans;
}
int main() {
	/*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    */
    fact[0]=1;
    invfact[0]=inverseMod(fact[0]);
    
    for(int i=1;i<2001;i++){
        fact[i]=(fact[i-1]*i)%K;
        invfact[i]=(invfact[i-1]*inverseMod(i))%K;
       // cout<<(fact[i]*invfact[i] )%K<<endl;
    }
    
    ll s;
    cin>>s;
    
    ll maxN=s/3LL;
    ll ans=0;
    for(ll i=1LL;i<=maxN;i++)
    {
        ll n=s-(3LL*i);
        ans= (ans+c(n+i-1LL,i-1LL))%K;
    }
    cout<<(ans+K)%K<<endl;
    
	return 0;
}
