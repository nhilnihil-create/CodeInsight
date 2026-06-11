#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);


	ll x, d, k;
	cin >> x >> k >> d;

	if(x > 0)
		x = -x;

	ll lo = 0, hi = min(k, (ll)1e18 / d), opt = -1;

	while(lo <= hi){
		ll mid = (lo + hi) >> 1ll;
		ll pos = x + mid * d;
		if(pos <= 0){
			opt = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}

	vector<ll> vals;

	ll s1 = x + opt * d;
	vals.push_back(s1);
	
	if(opt < k)
		vals.push_back(s1 + d);
	else
		vals.push_back(s1 - d);

	ll rem = k - opt;
	cout << abs(vals[rem % 2]) << endl;
	
	return 0;
}
