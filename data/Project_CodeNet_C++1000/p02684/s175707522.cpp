#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef unsigned long long ull;
typedef long long ll;

#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define speedhack() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define form(i, n) for (size_t i = 0; i < size_t(n); ++i)
#define forn(i, n) for (size_t i = 1; i <= size_t(n); ++i)

template<class T> using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll mod(ll a, ll b) { return (a%b+b)%b; }
ll gcd(ll x, ll y) { return __gcd(x, y); }
ll lcm(ll x, ll y) { return x * 1ll * y / gcd(x, y); }
 
const ll MAXN = 1e18;
const ll SIZE = 2e5 + 5;
const ll MOD  = 1e9 + 7;


ll n, k;
int a[SIZE];
vector<int> c;
bool used[SIZE];



void dfs (int v) {
	used[v] = true;
	c.push_back(v);
	if (!used[a[v]])
		dfs (a[v]);
}

int main() { speedhack()

	cin >> n >> k;
	forn (i, n)
		cin >> a[i];
	
	dfs (1);

	if ((int)c.size() - 1 < k && a[c.back()] == c.back())
		cout << c.back();
	else if ((int)c.size() - 1 >= k)
		cout << c[k];
	else {
		k -= ((ll)c.size() - 1);
		reverse (all(c));
		while (c.back() != a[c[0]])
			c.pop_back();
		reverse (all(c));
		n = c.size();
		int rem = ((k % n) == 0) ? n : (k % n);
		cout << c[rem - 1];
	}
	return 0;
}
