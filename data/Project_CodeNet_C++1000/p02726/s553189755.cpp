#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
const int siz = 2 * 1e3 + 7;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	clock_t begin = clock();
	int n, x, y;
	cin >> n >> x >> y;
	vector < int>v(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int dis = min({abs(i - j), abs(x - i) + abs(y - j) + 1, abs(y - i) + abs(x - j) + 1});
			//	cout << i << " " << j << " " << dis << endl;
			v[dis]++;
		}
	}
	for (int i = 1; i < n; i++) {
		cout << v[i] / 2 << endl;
	}
	cout << endl;
	clock_t end = clock();
	cerr << "Time run: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
}