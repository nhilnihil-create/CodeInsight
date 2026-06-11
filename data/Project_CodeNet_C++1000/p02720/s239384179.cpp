#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(false);

	int k; cin >> k;

	queue<ll> q;
	REP(i, 9) q.push(i + 1);

	ll num = 0;
	REP(i, k) {
		num = q.front();
		ll rem = num % 10;
		q.pop();
		if (rem != 0)
			q.push(10 * num + rem - 1);
		q.push(10 * num + rem);
		if (rem != 9)
			q.push(10 * num + rem + 1);
	}
	cout << num << '\n';
    return 0;
}
