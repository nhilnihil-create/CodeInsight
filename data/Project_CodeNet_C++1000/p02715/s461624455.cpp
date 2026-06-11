
	#include <bits/stdc++.h>
	using namespace std;
	
	typedef long long ll;
	#define pi 3.14159265 
	#define EPS 1e-8
	
	#define mod 1000000007
	#define fi first
	#define se second
	#define mp make_pair
	#define pb push_back
	#define endl "\n"

	const ll INF=(ll)2e18;
	
	long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
	}
	
	int main()
	{
		 ios_base::sync_with_stdio(false);
		 cin.tie(NULL);
			
		 ll n,k;
		 cin>>n>>k;
		 
		 vector<ll> ans(k+1,0);
		 ll res=0;
		 for(ll i=k;i>0;i--)
		 {
			 ans[i]=binpow(k/i,n,mod);
			 
			 for(ll j=2;(i*j)<=k;j++)
			 {
				 ans[i]-=ans[i*j];
				 ans[i]+=mod;
				 ans[i]%=mod;
			 }
			 res+=i*(ans[i]);
			 res%=mod;
		 }
		 cout<<res;
	}
