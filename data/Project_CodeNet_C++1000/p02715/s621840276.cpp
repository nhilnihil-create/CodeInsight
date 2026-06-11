#include<bits/stdc++.h>
#include<iostream>
#include<math.h>

using namespace std;

typedef long long int ll; 
const long long mod=1e9+7;

ll power(ll b,ll a) // a^b
{
	if(b==0)
		return 1LL;
	if(b==1)
		return a*1LL;
	if(b%2==0)
	{
		ll temp = power(b/2,a);
		temp = (temp*temp)%mod;
		return temp;
	}
	else
	{
		ll temp = power((b-1)/2,a);
		temp = (temp*temp)%mod;
		return (temp*a)%mod;		
	}

}

int main(void)
{
	ll n,k;
	cin >> n >> k;

	ll cnt[100005];

	ll ans=0;
	for(ll i=k;i>=1;i--)
	{
		cnt[i] = power(n,k/i);
		for(ll j=2*i;j<=k;j+=i)
			cnt[i] = (cnt[i]-cnt[j]+mod)%mod;
		

		ans = (ans + (cnt[i]*i)%mod)%mod;
		// ans = ans%mod;
		// cout << ans << endl;
	}

	cout << ans << endl;


	return 0;
}