#include<bits/stdc++.h>
#define ll long long int
#define pragi(a,b) for(ll i = a;i<b;i++)
#define pragj(a,b) for(ll j = a;j<b;j++)
#define pragk(a,b) for(ll k = a;k>=b;k--)
#define all(v) (v.begin(),v.end())
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define MP make_pair
#define MT make_tuple
#define F first
#define S second
#define KAKA ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long double ld;
typedef pair<int, int> pii;
//typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ll, ll> pll;

void Compute(ll n)
{
	KAKA
	vector<ll> ar(n);
	pragi(0,n)
	{
		cin>>ar[i];
	}
	vector<ll> x(61);
	vector<ll> y(61);
	pragi(0,n)
	{
		ll ele = ar[i];
		pragj(0,61)
		{
			if(ele & (1ll << j))//if jth bit is set
			{
				x[j]++;
			}
			else y[j]++;
		}
	}
	ll sum = 0;
	pragi(0,61)
	{
		ll a = ((x[i] % mod) * (y[i] % mod))%mod;
		ll b = (1ll << i)%mod;
		ll c = ((a % mod) * (b % mod))%mod;
		sum = ((sum % mod) + (c % mod))%mod;
	}
	cout<<sum<<"\n";
}
int main()
{
	KAKA
	ll n;
	cin>>n;
	Compute(n);
}