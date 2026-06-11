	#include <bits/stdc++.h>
	#include <ext/pb_ds/assoc_container.hpp>
	using namespace __gnu_pbds;
	using namespace std;
	#define mod 1000000007
	#define fi first
	#define se second
	#define mp make_pair
	#define pb push_back
	#define ps push
	#define pll pair<long,long>
	typedef long long ll;
	#define PI 3.14159265
	#define vi vector<pll> 
		 
	typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
	const ll INF=(ll)5e17;	
		
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
		
		ll m;
		cin>>m;
		ll s=0,d=0;
		for(ll i=0;i<m;i++)
		{
			ll d1,c1;
			cin>>d1>>c1;
			d+=c1;
			s+=(d1*c1);
		}
		d--;
		cout<<d+(s-1)/9;
		
	}
