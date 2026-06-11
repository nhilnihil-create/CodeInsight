#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

string v;
int n;
vector <int> rightswaps;
long long fact[200001];
long long invfact[200001];

long long fe(long long b, long long e) {
	long long a = 1;
	while (e != 0) {
		if (e % 2) {
			a *= b;
			a %= MOD;
		} 
		b *= b;
		b %= MOD;
		e >>= 1;
	}
	return a;
}

long long nPk(int n, int k) {
	if (n < k)
		return 0;
	return fact[n] * invfact[n - k] % MOD;
}

int main() {
	cin >> n >> v;
	fact[0] = 1;
	invfact[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		fact[i] = i * fact[i - 1] % MOD;
		invfact[i] = fe(fact[i], MOD - 2);
	}
	bool flipped = false;
	for (int i = 2 * n - 1; i >= 0; i--) {
		if (v[i] == 'W' && flipped) {
			rightswaps.push_back(i);
		} else if (v[i] == 'B' && !flipped) {
			rightswaps.push_back(i);
		}
		flipped = !flipped;
	}
	/*for (int i = 0; i < rightswaps.size(); i++)
		cout << rightswaps[i] << ' ';
	cout << endl;*/
	if (rightswaps.size() != n || rightswaps.back() == 0)
		cout << 0 << '\n';
	else {
		sort(rightswaps.begin(), rightswaps.end());
		long long ans = 1;
		long long cnt = 0;
		for (int i = n - 1; i >= 1; i--) {
			cnt++;
			ans *= nPk(cnt, rightswaps[i] - rightswaps[i - 1] - 1);
			ans %= MOD;	
			cnt -= (rightswaps[i] - rightswaps[i - 1] - 1);
		}
		ans *= nPk(cnt + 1, rightswaps[0]);
		ans %= MOD;
		ans *= fact[n];
		ans %= MOD;
		cout << ans << '\n';
	}
}