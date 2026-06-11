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

const ll mod = 998244353;

ll mod_exp(ll a, ll b){
	if(b == 0)
		return 1ll;
	if(b % 2 == 0){
		ll t = mod_exp(a, b / 2) % mod;
		return t * t % mod;
	}
	return a * mod_exp(a, b - 1) % mod;
}		

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, s;
	cin >> n >> s;

	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	vector<vector<ll>> dp(n + 2, vector<ll>(s + 5));
	dp[0][0] = mod_exp(2ll, n) % mod;
	ll inv2 = mod_exp(2ll, mod - 2) % mod;


	for(int i = 0; i < n; i++){
		for(int j = 0; j <= s; j++){
			
			//don't add
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;;

			//add
			if(j + a[i + 1] <= s)
				dp[i + 1][j + a[i + 1]] = (dp[i + 1][j + a[i + 1]] + dp[i][j] * inv2 % mod) % mod;	
		}
	}

	cout << dp[n][s] << endl;

	return 0;
}