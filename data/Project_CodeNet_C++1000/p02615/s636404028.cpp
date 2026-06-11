#include <bits/stdc++.h>

#define I_AM_SPEED ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;
#define double long double

int32_t main() {
	I_AM_SPEED
	int n;

	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(), greater<>());
	ll ans = 0;
	queue<int> q;
	q.push(a[0]);
	int c = 0;
	for(int i = 1 ; i < n ; i++){
		ans += q.front();
		q.pop();
		q.push(a[i]);
		q.push(a[i]);

	}
	cout << ans << endl;
}