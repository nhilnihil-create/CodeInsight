//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0516
#include <iostream>
#include <algorithm>
#include <vector>
#define INF (1<<30)
#define ll long long
using namespace std; 
int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	while (true) {
		ll n, k; cin >> n >> k;
		if (n == 0 && k == 0)break;
		vector<ll> Sum(n + 1);
		Sum[0] = 0;
		for (int i = 1; i <= n;i++) {
			ll N; cin >> N;
			Sum[i] = Sum[i - 1] + N;
		}
		ll ans = -INF;
		for (int i = 1; i <= n - k + 1;i++) {
			ans = max(ans, Sum[i+k-1] - Sum[i - 1]);
		}
		cout << ans << endl;
	}

}