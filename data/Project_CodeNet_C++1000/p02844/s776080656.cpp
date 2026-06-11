#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int INF = 1001001001;

ll pow_mod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) res = res * x % mod;
	return res;
}

int main() {
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				int cnt = 0;
				for (int now = 0; now < n; now++) {
					if ((int)(s[now] - '0') == i && cnt == 0) cnt++;
					else if ((int)(s[now] - '0') == j && cnt == 1) cnt++;
					else if ((int)(s[now] - '0') == k && cnt == 2) cnt++;
				}
				if (cnt == 3)ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}