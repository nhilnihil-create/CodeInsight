#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

ll power(ll base,ll exp)
{
    ll res=1;
    base=base%mod;

    while(exp>0)
    {
        if(exp & 1)
            res=(res*base)%mod;
        exp= exp >> 1;
        base= (base*base)%mod;
    }
    return res;


}

ll solve(ll n,ll r)
{
    ll fact[n+1];
    fact[0]=1;
    for(ll i=1;i<=n;i++)
    {
        fact[i]= fact[i-1]*i%mod;

    }

    ll ans= ((fact[n]%mod)*(power(fact[r],mod-2)%mod)*(power(fact[n-r],mod-2)%mod))%mod;
    return ans;


}
#define MAXN 2001
ll c[MAXN][MAXN];

void pascal()
{

    c[0][0]=1;
    for(ll n=1;n<MAXN;n++)
    {

        c[n][0]=c[n][n]=1;
        for(ll k=1;k<n;k++){
            c[n][k]= (c[n-1][k-1]%mod+ c[n-1][k]%mod)%mod;


        }
    }

}


int main()
{
    pascal();
    	ll n,k;
	 cin>>n>>k;

	 for(int i=1;i<=k;i++)
     {
         ll ans= c[n-k+1][i]*c[k-1][i-1]%mod;
         cout<<ans<<" ";
     }


	return 0;
}











