#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
#include<iterator>
#include<list>

using namespace std;

#define INF LLONG_MAX/5
#define MOD 1000000007
#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define enld endl

//(x^n)%mを返す
int power(int x, int n, int m) {
	int res = 1;
	x %= m;
	while (n > 0) {
		if (n % 2 == 1) {
			res = res * x % m;
		}
		x = x * x % m;
		n /= 2;
	}
	return res;
}

//nの逆元を返す
int invmod(int n, int m) {
	int ret = 0;
	ret = power(n, m - 2, m);
	return ret;
}

//nCk%MODを返す
//O(k)
int comb(int n, int k, int m) {
	int ans = 1;
	rep(i, k) {
		ans *= n - i;
		ans %= m;
		ans *= invmod(k - i, m);
		ans %= m;
	}
	return ans;
}

signed main() {
	int S;
	cin >> S;
	int ans = 0;
	for (int size = 1; size <= S / 3; size++) {
		int a = S - 3 * size;
		int b = size;
		ans += comb(a + b - 1, a, MOD);
		ans %= MOD;
	}
	cout << ans << endl;
}