#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
ll INF = 1000000007;
ll mod = 998244353;

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	vector<ll> cnt(n);
	int a;
	cin >> a;
	ll end = 0;
	if (a != 0) {
		cout << 0 << endl;
		return 0;
	}
	rep(i, n - 1) {
		ll k;
		cin >> k;
		cnt[k]++;
		end = max(end, k);
	}
	ll ans = 1;
	for(int i=1;i<=end;i++) {
		if (cnt[i] == 0 && cnt[i + 1] != 0) {
			cout << 0 << endl;
			return 0;
		}
	}
	if (cnt[0] != 0) {
		cout << 0 << endl;
		return 0;
	}
	cnt[0] = 1;
	for (int i = 1; i <= end; i++) {
		ans *= modpow(cnt[i-1], cnt[i], mod);
		ans %= mod;
	}
	cout << ans << endl;
}