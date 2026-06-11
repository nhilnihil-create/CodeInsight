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
	
	
	int n, m, k;
	cin >> n >> m >> k;

	vector<string> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	int ans = 0;

	for(int i = 0; i < (1 << n); i++){
		for(int j = 0; j < (1 << m); j++){
			vector<vector<bool>> f(n, vector<bool>(m));

			for(int k = 0; k < n; k++)
				if(i & (1 << k))
					for(int l = 0; l < m; l++)
						f[k][l] = true;

			for(int k = 0; k < m; k++)
				if(j & (1 << k))
					for(int l = 0; l < n; l++)
						f[l][k] = true;

			int cnt = 0;
			for(int k = 0; k < n; k++)
				for(int l = 0; l < m; l++)
					if(!f[k][l] && a[k][l] == '#')
						cnt++;

			ans += cnt == k;
		}
	}

	cout << ans << endl;

	return 0;
}
