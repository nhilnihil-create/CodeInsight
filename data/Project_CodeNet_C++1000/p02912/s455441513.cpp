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
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	clock_t begin = clock();
	int n, m;
	cin >> n >> m;
	priority_queue<ll>p;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		p.push(x);
	}
	for (int i = 0; i < m; i++) {
		ll have = p.top();
		p.pop();
		p.push(have / 2);
	}
	ll ans = 0;
	while (!p.empty()) {
		ans += p.top();
		p.pop();
	}
	cout << ans;
	clock_t end = clock();
	cerr << "Time run: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
}