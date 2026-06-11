#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;
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

	int n, k;
	cin >> n >> k;

	vector<int> cnt(n + 1);
	for(int i = 0; i < k; i++){
		int sz;
		cin >> sz;
		while(sz--){
			int x;
			cin >> x;
			cnt[x]++;
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans += (cnt[i] == 0);

	cout << ans << endl;

	return 0;
}
