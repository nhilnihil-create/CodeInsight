#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;

typedef tree <pii, null_type, less <pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int N = 5003;
int k, q, d[N], b[N];
ll a[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> k >> q;
	for (int i = 0; i < k; i++) {
		cin >> d[i];
	}
	while (q--) {
		int n, x, m;
		cin >> n >> x >> m;
		x %= m;
		ll total = 0;
		for (int i = 0; i < k; i++) {
			b[i] = d[i] % m;
			if (b[i] == 0) {
				b[i] = m;
			}
			total += b[i];
			//cout << b[i] << ' ';
		}
		//cout << '\n';
		int r = (n - 1) % k;
		int l = (n - 1) / k;
		a[0] = x;
		for (int i = 1; i <= r; i++) {
			a[i] = a[i - 1] + b[i - 1];
			//cout << "a[" << i << "] = " << a[i] << '\n';
		}
		cout << (n - 1) - (a[r] + l * total) / m << '\n';
	}
}
