#include <bit>
#include <bitset>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>


typedef long double ld;
typedef long long ll;

using namespace std;

#define M 62
#define MAXN (400000)
#define MOD ((ll) 1e9 + 7)

ll s[M][MAXN][2];
ll a[MAXN];
ll n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (ll i = 0; i < M; i++) {
		ll mask = (1LL << i);
		for (int j = n - 1; j >= 0; j--) {
			for (ll l = 0; l < 2; l++) {
				s[i][j][l] += s[i][j + 1][l];
				ll xmask = l << i;
				s[i][j][l] += (a[j] & mask) ^ xmask;
				s[i][j][l] %= MOD;
			}
		}
	}
/*	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < n; i++) {
			for (int l = 0; l < 2; l++) {
				cerr << j << " " << i << " " << l << " " << s[j][i][l] << endl;
			}
		}
	}
*/
	ll ret = 0;
	for (int i = 0; i < n - 1; i++) {
		for (ll j = 0; j < M; j++) {
			ll b = (a[i] & (1LL << j)) >> j;
//			cerr << j << " " << i + 1 << " " << b << " " << s[j][i + 1][b] << " " << b << endl;
			ret += s[j][i + 1][b];
			ret %= MOD;
		}
	}
	cout << ret << endl;
	return 0;
}
