#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 300005;
int n, a[MX], cn[MX], s[MX], res[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cn[a[i]]++;
	}
	sort(cn + 1, cn + n + 1);

	for (int i = 1; i <= n; i++)
		s[i] = s[i-1] + cn[i];

	for (int i = 1; i <= n; i++) {
		int j = lower_bound(cn + 1, cn + n + 1, i) - cn;
		int x = n - j + 1;
		x += s[j - 1] / i;
		res[x] = max(res[x], i);
	}

	for (int i = n - 1; i; i--)
		res[i] = max(res[i], res[i+1]);

	for (int i = 1; i <= n; i++)
		cout << res[i] << endl;

	return 0;
} 