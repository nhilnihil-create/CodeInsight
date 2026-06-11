#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
#include <atcoder/all>
 
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

	fenwick_tree<ll> fw(n);

	for(int i = 0; i < n; i++){
		ll x;
		cin >> x;
		fw.add(i, x);
	}

	for(int i = 0, t; i < q; i++){
		cin >> t;
		if(t == 0){
			int p;
			ll x;
			cin >> p >> x;
			fw.add(p, x);
		}
		else{
			int l, r;
			cin >> l >> r;
			cout << fw.sum(l, r) << endl;
		}
	}

	return 0;
}
