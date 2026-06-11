#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>
#define PI 3.141592653589793
const int INF = 1001001001;
const ll MX = 1e18;
const int mod = 1000000007;

int main() {
	int n;
	cin >> n;
	vector<ll>a(n+1),b(n);
	rep(i, n+1) {
		cin >> a[i];
	}
	rep(i, n) {
		cin >> b[i];
	}
	ll ans = 0;
	rep(i, n) {
		if (b[i] > a[i]) {
			if (b[i] > a[i] + a[i + 1]) {
				ans += a[i + 1];
				ans += a[i];
				a[i + 1] = 0;
			}
			else {
				ans += b[i];
				a[i + 1] =a[i+1] - b[i] + a[i];
			}
		}
		else {
			ans += b[i];
		}
	}
	cout << ans << endl;
}
