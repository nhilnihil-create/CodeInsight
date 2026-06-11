#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

int get(int x) {
	if (x < 10) {
		return x + x * 10;
	}
	int temp = x % 10;
	while (1) {
		x /= 10;
		if (x < 10) {
			temp += x * 10;
			break;
		}
	}
	return temp;
}

int inv(int x) {
	if (x < 10) {
		return x + x * 10;
	}
	int temp = x % 10;
	while (1) {
		x /= 10;
		if (x < 10) {
			temp = temp * 10 + x;
			break;
		}
	}
	if (temp < 10) {
		return 101;
	}
	return temp;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    scanf("%d", &n);
    ll res = 0;
    map <int, int> mp1, mp2;
    for (int i = 1; i <= n; i++) {
		//printf("%d: %d %d\n", i, get(i), inv(i));
		mp1[get(i)]++;
		mp2[inv(i)]++;
	}
	for (auto x : mp1) {
		if (mp2.count(x.fi)) {
			res += (ll)x.se * mp2[x.fi];
		}
	}
	printf("%lld", res);
    return 0;
}
