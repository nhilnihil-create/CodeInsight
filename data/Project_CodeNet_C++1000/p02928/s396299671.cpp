#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define fastcin() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define heap priority_queue
using namespace std;
typedef pair<int, int> ii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2700, mod = 1e9 + 7; 
int n, k, a[maxn]; 
signed main()
{ 
	cin >> n >> k; 
	for(int i = 1; i <= n; i++) cin >> a[i]; 
	int ans = 0, K = (k * (k + 1) / 2) % mod, KK = (k * (k - 1) / 2) % mod; 
	for(int i = 1; i <= n; i++) {
		int l = 0, r = 0; 
		for(int j = 1; j < i; j++) l += (a[j] > a[i]); 
		for(int j = i + 1; j <= n; j++) r += (a[j] > a[i]); 
		ans = (ans + l * K % mod + r * KK % mod) % mod; 
	}
	cout << ans; 
}
