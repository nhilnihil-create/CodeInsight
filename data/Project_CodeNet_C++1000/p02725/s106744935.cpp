#include <bits/stdc++.h>
using namespace std;
using namespace __detail;

typedef long long ll;
#define ar array
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define fork(i, n) for (ll i = 0; i < (n); i++)
#define forn for (ll i = 0; i < (n); i++)
#define fori(i, k, n) for (ll i = k; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define en '\n'
#define FILL(x, v) memset(x, v, sizeof(x))
#define pb push_back
#define fast                 \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);

template <typename A, typename B>
inline void chmin(A &a, B b)
{
	if (a > b)
		a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b)
{
	if (a < b)
		a = b;
}
template <typename T>
void print(vector<T> &a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << en;
}
template <typename T>
void print(deque<T> &a)
{
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << en;
}
template <typename T>
void print(vector<vector<T>> &a)
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
			cout << a[i][j] << ' ';
		cout << en;
	}
}

void solve()
{
	// ll x, c = 100;
	// int ans = 0;
	// cin >> x;
	// while (c < x)
	// {
	// 	c += c / 100;
	// 	ans++;
	// }
	// cout << ans << en;
	int k, n;
	cin >> k >> n;
	vi a(n);
	int ans = k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		// chmin(ans, (i > 0 ? k - abs(a[i] - a[i - 1]) : k - abs(a[i] - a[n - 1])));
		int prev = (i == 0) ? a[n - 1] : a[i - 1];
		int dist = abs(a[i] - prev);
		chmin(ans, max(dist, k - dist));
	}
	cout << ans << en;
}

int main()
{
	fast;
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}