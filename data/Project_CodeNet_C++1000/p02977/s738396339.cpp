#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1005;
int n;
vi a;

bool valid (vi &a) {
	for (int i = 1; i <= n; i++) {
		int x, y;

		forn (j, 2 * n) {
			if (a[j] == i) x = j;
			if (a[j] == i + n) y = j;
		}

		if (x > y) swap(x, y);
		
		int acu = 0;
		for (int k = x; k <= y; k++)
			acu ^= a[k] > n ? a[k] - n : a[k];
		
		if (acu != i)
			return 0;
	}

	return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	if (__builtin_popcount(n) == 1) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;

	int x = 0;
	for (int i = 0; x + (1 << i) <= n; i++)
		x += 1 << i;

	for (int i = 1; i < x; i++)
		cout << i << " " << i + 1 << endl;

	cout << x << " " << n + 1 << endl;
	
	for (int i = 1; i < x; i++)
		cout << n + i << " " << n + i + 1 << endl;

	for (int i = x + 1; i + 1 <= n; i += 2) {
		cout << i << " " << i + 1 << endl;
		cout << i + 1 << " " << 1 << endl;
		cout << 1 << " " << n + i << endl;
		cout << n + i << " " << n + i + 1 << endl;
	}

	if (n % 2 == 0) {
		int mx = 0, acu = 0;

		for (int i = 1;; i++) {
			acu ^= i;
			if (__builtin_popcount(i) != 1) continue;
			if (n & i) {
				mx = i;
				break;
			}
		}

		int y = n ^ acu;
		if (y % 2)
			cout << n << " " << y << endl;
		else
			cout << n << " " << n + y << endl;
		cout << mx << " " << 2 * n << endl;
	}

	return 0;
	a.resize(2 * n);
	iota(all(a), 1);

	do {
		if (valid(a)) {
			for (int x : a) cout << x << " ";
			cout << endl;
		}
	} while (next_permutation(all(a)));

	return 0;
}
