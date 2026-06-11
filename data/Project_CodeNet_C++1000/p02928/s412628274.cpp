#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	long long ans= 0,k,modk,mod = 1000000007;
	cin >> n >> k;
	vector<int> a(n),invs_my(n,0),invs_other(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j])invs_my[i]++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] > a[j])invs_other[i]++;
		}
	}

	for (int i = 0; i < n; i++) {

		modk = ((k - 1) * k / 2)%mod;
		ans = (ans + modk * invs_other[i]) %mod;
		ans = (ans + k * invs_my[i]) % mod;
	}
	cout << ans << endl;


}
