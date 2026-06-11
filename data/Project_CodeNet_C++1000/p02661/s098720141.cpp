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
 
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);


	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	for(int i = 0; i < n; i++)
		cin >> a[i] >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	ll x = 0, y = 0;
	if(n % 2 == 0){
		x = a[n / 2] + a[n / 2 - 1];
		y = b[n / 2] + b[n / 2 - 1];
	}
	else{
		x = a[n / 2];
		y = b[n / 2];
	}

	cout << y - x + 1 << endl;

	return 0;
}