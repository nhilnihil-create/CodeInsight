#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
#include <queue>
#include <map>
using namespace std;

#define rip(i,n,s) (int i=(s);i<(int)(n);i++)
#define all(a) (a).begin(),(a).end()
long long mod = 1000000007;

long long powr(long long n, long long p, long long k) {//n^k(mod p)
	if (k != 0) {
		if (p % 2 == 0) {
			long long x = powr(n, p, k / 2);
			return (long long)x*x%p;
		}
		else {
			long long x = powr(n, p, k - 1);
			return (long long)x*n%p;
		}
	}
	return 1;
}

long long rev(long long n, long long p) {//nの逆元
	return powr(n, p, p - 2);
}

long long bino(long long n, long long m, long long p) {//nCm(mod p)
	long long me = 1;
	long long ans = 1;
	for (int i = 0;i < n + m;i++) {
		me = (long long)(i + 1) * ans % p;
		if (i == m - 1) {
			ans = (long long)rev(me, p) * ans%p;
		}
		if (i == m - n - 1) {
			ans = (long long)(rev(me, p))*ans%p;
		}
	}
	ans = (long long)(ans*me%p);
	return ans;
}

struct modint {
	long long num;
	long long p;
	modint() {
		num = 0;
		p = 1000000007;
	}
	modint(int x) {
		num = (long long)x%p;
		p = 1000000007;
	}
	modint operator+(const modint &other) {
		modint ret;
		ret.p = p;
		ret.num = (num + other.num) % p;
		return ret;
	}
	modint operator+(const long long &other) {
		modint ret;
		ret.p = p;
		ret.num = (num + (other%p)) % p;
		return ret;
	}
	modint operator-(const modint &other) {
		modint ret;
		ret.p = p;
		ret.num = (num - other.num + p) % p;
		return ret;
	}
	modint operator-(const long long &other) {
		modint ret;
		ret.p = p;
		ret.num = (num - (other%p) + p) % p;
		return ret;
	}
	modint operator*(const modint &other) {
		modint ret;
		ret.p = p;
		ret.num = (num*other.num) % p;
		return ret;
	}
	modint operator*(const long long &other) {
		modint ret;
		ret.p = p;
		ret.num = (num*(other%p)) % p;
		return ret;
	}
	modint operator/(const modint &other) {
		modint ret;
		ret.p = p;
		ret.num = (num*rev(other.num, p)) % p;
		return ret;
	}
	modint operator/(const long long &other) {
		modint ret;
		ret.p = p;
		ret.num = (num*rev(other%p, p)) % p;
		return ret;
	}
};

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	long long mad=1;
	for rip(i, n, 0) {
		mad = mad * (i + 1) % mod;
	}
	vector<bool> da(n * 2);
	for rip(i, n * 2, 0) {
		da[i] = (s[i] == 'B');
	}
	vector <bool> dir(n * 2);
	dir[0] = da[0];
	for rip(i, n * 2, 1) {
		dir[i] = !(da[i] ^ da[i - 1] ^ dir[i-1]);
	}
	long long co = 0;
	long long ans=1;
	for (int i = n * 2 - 1;i > -1;i--) {
		if (!dir[i]) {
			co++;
		}
		else {
			ans = (ans * co)%mod;
			co--;
		}
	}
	ans = (ans * mad)%mod;
	if (co==0) {
		cout << ans << endl;
	}
	else {
		cout << 0 << endl;
	}
}