#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define mod 1000000007
#define PI 3.1415926535
using namespace std;
ll power(ll x, ll y)
{
	if (y == 0)
		return 1;
	else if (y % 2 == 0)
		return power(x, y / 2) * power(x, y / 2);
	else
		return x * power(x, y / 2) * power(x, y / 2);
}
ll modExpo(ll x,ll n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return modExpo((x*x)%mod,n/2);
    else                            
        return (x*modExpo((x*x)%mod,(n-1)/2))%mod;
 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	string s,t;
	cin>>s>>t;
	ll ans=t.size();
	for(ll i=0;i<=s.size()-t.size();i++)
	{
		ll c=0;
		for(ll j=0;j<t.size();j++)
		{
			if(s[i+j]!=t[j])
				c++;
		}
		ans=min(ans,c);
	}
	cout<<ans<<endl;
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}