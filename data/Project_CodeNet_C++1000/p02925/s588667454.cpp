#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
using namespace std;
#define pie 3.141592653589793238462643383279
#define mod 100000
#define INF 100000000000000000
#define int long long
#define all(vec) vec.begin(),vec.end()
#define P pair<int,int>
#define S second
#define F first

int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
bool prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0)return false;
	}
	return true;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= mod;
	}
	return res;
}
int mod_pow(int x, int y, int m) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}

int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2, mod) % mod;
}

int n, a[1010][1010];
int cum[1010][1010];
int cnt2;
vector<int> vec[1000010];
int cnt[1000010];
queue<P> que;
int ans;

signed main() {
	cin >> n;
	int x = n * (n - 1) / 2;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			cnt2++;
			cum[i][j] = cnt2;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < n; j++) {
			cin >> a[i][j];
			if (2 <= j) {
				vec[cum[min(i, a[i][j - 1])][max(i, a[i][j - 1])]].push_back(cum[min(i, a[i][j])][max(i, a[i][j])]);
				cnt[cum[min(i, a[i][j])][max(i, a[i][j])]]++;
			}
		}
	}
	int cnt3 = 0;
	for (int i = 1; i <= x; i++) {
		if (!cnt[i])que.push({ i,1 });
	}
	while (!que.empty()) {
		P p = que.front(); que.pop();
		ans = max(ans, p.second);
		cnt3++;
		int v = p.first;
		for (int i = 0; i < (int)vec[v].size(); i++) {
			cnt[vec[v][i]]--;
			if (!cnt[vec[v][i]])que.push({ vec[v][i],p.second + 1 });
		}
	}
	if (cnt3 != x)cout << -1 << endl;
	else cout << ans << endl;
}