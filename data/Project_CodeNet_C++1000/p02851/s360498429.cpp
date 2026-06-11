#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <climits>
#define mk make_pair
#define pb push_back
#define scanf scanf_s
#define printf printf_s
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll, ll> pos;
const ll N = 200010, MOD = 1000000007;

ll mn(ll a, ll b) {
	if (a == -1)return b;
	if (b == -1)return a;
	return min(a, b);
}

int bb(int v1) {
	if (v1 % 2 == 0)return v1 / 2 - 1;
	else return v1 / 2;
}

ll pw(ll a, ll b) {
	ll v = 1;
	for (; b > 0; b = (b >> 1), a = (a * a) % MOD) {
		if ((b & 1) > 0)v = (v * a) % MOD;
	}
	return v;
}

ll n, k, a[N],ans=0;
map<int, int> mp;
int main() {
	cin >> n >> k;
	mp[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (i - k  >= 0) {
			ll v2 = (a[i - k ] - (i - k) % k + k) % k;
			mp[v2]--;
		}

		cin >> a[i];
		a[i] = (a[i] + a[i - 1]) % k;
		ll v1 = (a[i] - i%k + k) % k;
		ans += mp[v1];
		mp[v1]++;
	}
	cout << ans << endl;
	return 0;
}
