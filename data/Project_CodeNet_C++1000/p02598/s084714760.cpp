//libraries
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

//namespace
using namespace std;
using namespace __gnu_pbds;

//typedef
//typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//typedef tree<long long,null_type,greater<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set1;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;

//define
#define i(X) cin>>X;
#define ol(X) cout<<X<<endl;
#define os(X) cout<<X<<" ";
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define line cout<<"\n";
#define pbp(a,b) push_back(make_pair(a,b));
#define vll(A) vector<ll> A;
#define ivt(A,n,p) vector<ll> A(n,p);
#define vst(A) sort(A.begin(),A.end());
#define rvst(A) sort(A.rbegin(),A.rend());
#define forin(i,a,b) for(ll i=a;i<=b;i++)
#define forde(i,a,b) for(ll i=a;i>=b;i--)
#define fio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const long long inf=(long long)1e18;
long long MOD=(long long)(1e9+7);

ll power(ll x,ll y)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2) % MOD;
    p = (p * p) % MOD;

    return (y%2 == 0)? p : (x * p) % MOD;
}
ll modInverse(ll a)
{
   return power(a,MOD-2);
}

bool p(ll a[],ll n,ll mn,ll k)
{
	forin(i,0,n-1)
	{
		k-=(a[i]+mn-1)/mn-1;
		if(k<0)
		return false;
	}
	return k>=0;
}
int main() 
{
	// #ifndef ONLINE_JUDGE
    //    freopen ("input.txt" , "r" , stdin);
	// 	// freopen ("OUTPUT.txt" , "w" , stdout);
	// #endif
	fio;
	ll testcase=1;
	//cin>>testcase;
	while(testcase--)
	{
		ll n,k;
		cin>>n>>k;
		ll ans=0;
		ll a[n];
		forin(i,0,n-1)
		{
			cin>>a[i];
		}
		ll mn=1,mx=1e9+5;
		while(mn!=mx)
		{
			ll md=(mn+mx)/2;
			if(p(a,n,md,k))
			{
				mx=md;
			}
			else
			{
				mn=md+1;
			}
		}
		cout<<mn<<endl;
	}
	return 0;
}