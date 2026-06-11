#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace __gnu_pbds;
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<long long,long long> ii; 	
typedef complex<long double> com;

const ll mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector <ll> arr(n+1);
	for (int z=0;z<=n;z++){
		cin >> arr[z];
	}
	ll i = 1;
	vector <ll> maxi(n+1);
	for (int z=0;z<=n;z++){
		maxi[z] = i;
		i -= arr[z];
		if (i <= ll(1e17)){
			i *= 2;
		}
		if (z == n){
			if (i < 0){
				cout << -1 << endl;
				return 0;
			}
		} else {
			if (i <= 0){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	ll ans = 0;
	ll cul = 0;
	for (int z=n;z>=0;z--){
		cul += arr[z];
		cul = min(cul,maxi[z]);
		ans += cul;
	}
	cout << ans << endl;
}