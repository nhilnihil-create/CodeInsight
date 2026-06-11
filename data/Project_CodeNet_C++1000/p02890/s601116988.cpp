#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define mp make_pair
#define all(x) (x).begin(), (x).end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 3e5 + 123;
int n, a[N], cnt[N];
ll p[N];

int get(int x) {
	int pos = lower_bound(cnt + 1, cnt + n + 1, x) - cnt;
	return (n - pos + 1) + (p[pos - 1] / x);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	sort(cnt + 1, cnt + n + 1);
	for (int i = 1; i <= n; i++) {
		p[i] = p[i - 1] + cnt[i];
	}
	for (int k = 1; k <= n; k++) {
		int l = 0, r = n / k + 1;
		while (l < r - 1) {
			int mid = l + r >> 1;
			if (get(mid) >= k) {
				l = mid;
			}	else {
				r = mid;
			}
		}
		cout << l << '\n';
	}
}
