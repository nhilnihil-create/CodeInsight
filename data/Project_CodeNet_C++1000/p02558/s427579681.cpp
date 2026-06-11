#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
#include <atcoder/dsu>
 
using namespace std;
using namespace __gnu_pbds;
using namespace atcoder;
 
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
 
	// freopen("capastaty_input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n, q;
	cin >> n >> q;

	dsu d(n);

	for(int i = 0; i < q; i++){
		int t, a, b;
		cin >> t >> a >> b;

		if(t == 0)
			d.merge(a, b);
		else
			cout << d.same(a, b) << endl;
	}

	return 0;
}
