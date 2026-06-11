#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(x) x.begin(), x.end()

#define mp make_pair
#define in insert
#define er erase
#define con continue
#define pb push_back
#define sc scanf
#define pr printf
#define ub upper_bound
#define lb lower_bound
#define s second
#define f first
#define int long long

const long long infl = 1e18; 
const int N = 3e5 + 300, N2 = 2e3, inf = 1e9 + 200, mod = 1e9 + 7;

set <int> S;
vector <int> g;
int n, m, k;
int a[N], ans[N], us[N];
string ss;

int bin_pow(int x, int y){
	int res = 1;
	while (y){
		if (y & 1) (res *= x) %= mod;
		(x *= x) %= mod;
		y >>= 1;
	}
	return res;
}

int f(int x){
	return bin_pow((k / x), n);
}

int rec(int x){
	if (us[x]) return ans[x];
	us[x] = 1;
	ans[x] = f(x);
	for (int i = 2; i * x <= k; i++){
		ans[x] -= rec(i * x);
		ans[x] = (ans[x] + mod) % mod;
	}
	return ans[x];
}

main (){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	int res = 0;
	for (int i = 1; i <= k; i++){
		(res += (rec(i) * i) % mod) %= mod;
	}
	cout << res;
	return 0;
}










