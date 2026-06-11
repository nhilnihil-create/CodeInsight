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
using namespace std;
#define pie 3.141592653589793238462643383279
#define int long long
#define mod 1000000007
#define INF 1145141919364364
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

int kai(int x) {
	if (x == 0)return 1;
	return kai(x - 1)*x%mod;
}

int mod_pow(int x, int y, int mood) {
	int res = 1;
	while (y > 0) {
		if (y & 1)res = res * x%mood;
		x = x * x%mood;
		y >>= 1;
	}
	return res;
}

int comb(int x, int y) {
	return kai(x)* mod_pow(kai(x - y), mod - 2, mod) % mod * mod_pow(kai(y), mod - 2, mod) % mod;
}

int n;
int ans[510][510];

signed main() {
	cin >> n;
	int cnt = 0;
	for (int i = 2; i < 2 * n; i *= 2) {
		cnt++;
		for (int j = 1; j <= n; j++) {
			for (int k = j + i / 2; k <= n; k += i) {
				ans[j][k] = cnt;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}