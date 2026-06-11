#include <bits/stdc++.h>
#include <unordered_set>
#include <random>
using namespace std;
#define ll long long
#define fr first
#define sc second
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()

int N, P;
string s;

ll modpow(ll a, ll b) {
	if (b == 0) return 1;
	if (b & 1) return modpow(a, b - 1) * a % P;
	ll half = modpow(a, b / 2) % P;
	return (half * half) % P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> P >> s;

	reverse(all(s));
	if (P != 2 && P != 5) {
		ll tmp = 0;
		ll cnt[11000] = { 0 };
		for (int i = 0; i < s.size(); i++) {
			tmp += (s[i] - '0') * modpow(10, i);
			tmp %= P;
			cnt[tmp]++;		
		}

		ll ans = 0;
		cnt[0]++;
		for (int i = 0; i < P; i++) ans += cnt[i] * (cnt[i] - 1) / 2;
		cout << ans << '\n';
	}
	else {
		ll ans = 0;
		if (P == 2) {
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '0')
					ans += s.size() - i;
			}
		}
		else if (P == 5){
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '5' || s[i] == '0')
					ans += s.size() - i;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}