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
  
#define pb push_back
#define mp make_pair
#define in insert
#define f first
#define s second
#define ll long long
#define dd double
  
const int mod = 1e9 + 7;
const int N = 2e5 + 7;
const int inf = 2e9;
const ll INF = 1e18;

// int mmax[N], cnt[N], a[N];
int l[N], r[N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// freopen("*.in", "r", stdin);freopen("*.out", "w", stdout);
	int n, k, c;
	string s;
	cin >> n >> k >> c >> s;

	// for (int i = n - 1; i >= 0; i--) {
	// 	if (i + c + 1 > n) cnt[i] = (s[i] == 'o');
	// 	else cnt[i] = mmax[i + c + 1] + (s[i] == 'o');
	// 	mmax[i] = min(max(mmax[i + 1], cnt[i]), k);
	// }

	// for (int i = 0; i < n; i++) {
	// 	if (s[i] == 'x') continue;
	// 	a[mmax[i]]++;
	// 	if (mmax[i + 1] < mmax[i] && a[mmax[i]] == 1) {
	// 		cout << i + 1 << "\n";
	// 		i += c;
	// 	}
	// }
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'x') continue;
		l[cnt] = i;
		i += c;
		cnt++;
		if (cnt == k) break;
	}

	cnt = k - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == 'x') continue;
		r[cnt] = i;
		i -= c;
		cnt--;
		if (cnt == -1) break;
	}

	for (int i = 0; i < k; i++) {
		if (l[i] == r[i]) cout << l[i] + 1 << "\n";
	}
}