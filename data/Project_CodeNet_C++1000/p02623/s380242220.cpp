#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define read freopen("in.txt", "r", stdin)
#define write freopen("out.txt", "w", stdout)
#define mem(x, n) memset(x, n, sizeof(x))
#define all(x) x.begin(), x.end()
#define endl "\n"

int main() {
	faster;

	ll n, m, t, in, tot = 0, time = 0;
	cin >> n >> m >> t;

	vector<ll> a(n + 1), b(m + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int i, j;
	for (i = 0; i < n; i++) {
		if (a[i] + time <= t) {
			time += a[i];
			tot++;
		} else {
			break;
		}
	}
	i--;

	ll temp = tot;

	for (j = 0; j < m; j++) {
		time += b[j];
		temp++;
		while (i >= 0 && time > t) {
			time -= a[i];
			i--;
			temp--;
		}

		if (time <= t) {
			tot = max(tot, temp);
		} else {
			break;
		}
	}

	cout << tot << endl;
	return 0;
}