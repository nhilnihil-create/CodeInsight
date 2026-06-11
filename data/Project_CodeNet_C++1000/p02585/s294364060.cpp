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

	const ll oo = 1e18;

	int n, k;
	cin >> n >> k;

	vector<int> p(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> p[i];

	vector<ll> c(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> c[i];

	ll ans = -oo;
	vector<bool> used(n + 1);

	for(int i = 1; i <= n; i++){
		if(used[i])
			continue;

		vector<ll> cycle;
		int u = i;
		ll sum = 0;
		while(!used[u]){
			used[u] = true;
			sum += c[u];
			cycle.push_back(c[u]);
			u = p[u];
		}

		int sz = cycle.size();
		for(int i = 0; i < sz; i++){

			//take 0 rem
			if(sum > 0)
				ans = max(ans, sum * 1ll * (k / sz));

			ll cur = cycle[i], add = 0;
			int cnt = 1;
			int rem = k - cnt;
			int rounds = rem / sz;
			if(sum >= 0)
				add = sum * 1ll * rounds;

			ans = max(ans, cur + add);

			for(int j = (i + 1) % sz; j != i && cnt + 1 <= k; j = (j + 1) % sz){
				cnt++;
				cur += cycle[j];
				rem = k - cnt;
				rounds = rem / sz;
				add = 0;
				if(sum >= 0)
					add = sum * 1ll * rounds;

				ans = max(ans, cur + add);
			}
		}
	}


	cout << ans << endl;
	
	return 0;
}
