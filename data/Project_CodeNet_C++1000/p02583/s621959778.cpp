#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

bool good(ll a, ll b, ll c) {
	if (a == b || b == c)
		return false;
	return a + b > c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<ll> l(n);
	for (int i = 0 ; i < n ; ++i) {
		cin >> l[i];
	}
	sort(l.begin(), l.end());
	int c = 0;
	for (int i = 0 ; i < n ; i++) {
		for (int j = i + 1 ; j < n ; j++) {
			for (int k = j + 1 ; k < n ; k++) {
				c += good(l[i], l[j], l[k]);
			}
		}
	}
	cout << c << "\n";
	

	return 0;
}
