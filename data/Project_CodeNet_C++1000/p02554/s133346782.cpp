#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf  1e18
#define mk(arr,n,type) type *arr=new type[n];
#define ti(arr,n) for(ll i=0;i<n;++i)cin>>a[i];
#define ot(arr,n) for(ll i=0;i<n;++i)cout<<a[i]<<" ";
#define str(a) string a;cin>>a;
#define w(x) int x;cin>>x;while(x--)
ll mod_pow(ll n, ll i)
{
	if (i == 0)
		return 1;
	ll res = mod_pow(n, i / 2) % mod;
	if (i % 2 == 0)
		return (res * res) % mod;
	else
		return (((res * res) % mod) * n) % mod;
}
int main()
{
	ll n; cin >> n;
	ll add = 0;
	add = (mod_pow(10, n) + mod_pow(8, n)) % mod;
	ll sub = (mod_pow(9, n) * 2) % mod;
	ll ans = (mod + add - sub) % mod;
	cout << ans;

}