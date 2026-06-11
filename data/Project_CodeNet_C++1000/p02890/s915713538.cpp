#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18)
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P std::pair<int,int>
#define PiP std::pair<int,std::pair<int,int>>
#define all(v) v.begin(),v.end()
#define mkp std::make_pair
#define prique(T) std::priority_queue<T,vector<T>,greater<T>>
using namespace std;
template<class T> inline void chmax(T& a, T b) { a = std::max(a, b); }
template<class T> inline void chmin(T& a, T b) { a = std::min(a, b); }

bool prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)return false;
	}
	return x != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
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
int get_rand(int MIN, int MAX) {
	std::random_device rnd;
	std::mt19937_64 mt64(rnd());
	std::uniform_int_distribution<int>engine(MIN, MAX);
	return engine(mt64);
}
/*--------Library Zone!--------*/

int n;
map<int, int>mp;
int shuru[333333];
signed main() {
	cin >> n;
	rep(i, n) {
		int a; cin >> a; mp[a]++;
	}
	int ma = 0;
	for (auto p : mp) {
		shuru[p.second]++;
		chmax(ma, p.second);
	}
	int siz = mp.size();
	REP(i, n + 1) {
		if (siz < i)cout << 0 << endl;
		else {
			int s[333333];
			s[0] = 0;
			REP(j, ma + 1)s[j] = shuru[j];
			int mab = ma;
			int ans = 0;
			bool flag;
			while (mab) {
				flag = false;
				if (s[mab] > i) {
					int plus = s[mab] / i;
					s[mab - 1] += plus * i;
					s[mab] -= plus * i;
					ans += plus;
					flag = true;
				}
				else {
					int cnt = 0;
					int memo = 0;
					for (int j = mab; j > 0; j--) {
						if (cnt + s[j] >= i) {
							s[j] += memo;
							s[j] -= i - cnt;
							s[j - 1] += i - cnt;
							mab--;
							ans++;
							flag = true;
							break;
						}
						int memo2 = s[j];
						s[j] = 0;
						s[j] += memo;
						memo = memo2;
						cnt += memo2;
					}
				}
				if (!flag)break;
			}
			cout << ans << endl;
		}
	}
}
