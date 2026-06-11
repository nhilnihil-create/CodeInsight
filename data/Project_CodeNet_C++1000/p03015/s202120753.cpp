#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (ll i = (ll)a; i <= (ll)b; i++)
#define DEC(i, a, b) for (ll i = (ll)a; i >= (ll)b; i--)
#define f first
#define s second

string l;
ll ans, m = 1e9+7, coun, three[100005], two[100005];

int main() {
	three[0] = 1;
	FOR(i, 1, 100000) {
		three[i] = 3 * three[i-1];
		three[i] %= m;
	}
	two[0] = 1;
	FOR(i, 1, 100000) {
		two[i] = 2 * two[i-1];
		two[i] %= m;
	}
	cin >> l;
	FOR(i, 0, l.length()-1) {
		//cout << (l[i] == '0') << ' ';
		if (l[i] == '0') continue;
		//cout << coun * 2 + three[l.length() - i - 1] << ' ';
		ans += (two[coun] * three[l.length() - i - 1]) % m;
		ans %= m;
		coun++;
	}
	ans += two[coun];
	ans %= m;
	cout << ans;
}
