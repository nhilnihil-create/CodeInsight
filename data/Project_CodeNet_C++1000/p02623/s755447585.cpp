#include <bits/stdc++.h>
using namespace std;

#pragma warning( disable : 4996 )

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ss(s) scanf("%s", &s)
#define pi(n) printf("%d\n", n)
#define pll(n) printf("%lld\n", n)
#define ps(s) printf("%s\n", s)
#define FOR(i, a, b) for (int i=a;i<=b;i++)

typedef long long ll;



void solve() {
	//input
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n);
	for (auto& i : a) sll(i);
	vector<ll> b(m);
	for (auto& i : b) sll(i);

	//pre_sum O(n)
	vector<ll> a_sum(n + 1);
	a_sum[0] = 0;
	a_sum[1] = a[0];
	FOR(i, 2, n) {
		a_sum[i] = (ll)a_sum[i - 1] + a[i - 1];
	}
	vector<ll> b_sum(m + 1);
	b_sum[0] = 0;
	b_sum[1] = b[0];
	FOR(i, 2, m) {
		b_sum[i] = (ll)b_sum[i - 1] + b[i - 1];
	}
	//dp O(nlogm)
	int max_book = 0;
	FOR(i, 0, n) {
		if (a_sum[i] > k) {
			break;
		}
		//two pointers
		int l = 0, r = m, mid;
		while (l < r) {
			mid = (l + r) / 2;
			ll sum1 = b_sum[mid] + a_sum[i];
			ll sum2 = b_sum[mid + 1] + a_sum[i];
			if (sum1 <= k && sum2 > k) {
				break;
			}
			else if (sum1 > k) {
				r = mid - 1;
			}
			else if (sum1 < k) {
				l = mid + 1;
			}
		}
		mid = (l + r) / 2;
		max_book = max(max_book, i + mid);

	}
	cout << max_book << endl;
}

int main() {
	solve();
}