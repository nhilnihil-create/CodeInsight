#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
const ll INF = 1000000007;

int main() {
	int n;
	ll k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> b(n), c(n);
	for(int i=0;i<n-1;i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) b[i]++;
		}
	}
	rep(i, n) {
		rep(j, n) {
			if (a[i] > a[j]) c[i]++;
		}
	}
	ll ans = 0;
	rep(i, n) {
		ans = (ans+(c[i] * ((k * (k - 1) / 2)%INF)) % INF)%INF;
		ans = (ans+((b[i] * k) % INF))%INF;
	}
	cout << ans << endl;
}
