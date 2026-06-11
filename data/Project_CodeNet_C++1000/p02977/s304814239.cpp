#include<bits/stdc++.h>
const int maxn = 200200;
const int mod = 998244353;
typedef long long ll;
inline ll pow(ll a,int b,ll ans = 1) {
	for(;b;b >>= 1,a = a * a % mod) if(b & 1) ans = ans * a % mod;
	return ans;
}
inline ll inverse(int x){ return pow(x, mod - 2); }
inline void reduce(int & x){ x += x >> 31 & mod; }
inline void link(int x,int y) {
	std::cout << x << ' ' << y << '\n';
}
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
int n;
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	if(n & n - 1) {
		std::cout << "Yes" << '\n';
		link(1, n + 2);
		link(n + 2, 3);
		link(3, n + 1);
		link(n + 1,2);
		link(2,n + 3);
		for(int i = 4;i < n;i += 2) {
			link(n + 1, i), link(i, n + i + 1);
			link(n + 1,i + 1), link(i + 1,n + i);
		}
		if(n % 2 == 0) {
			int t = 1 << __builtin_ctz(n);
			link(n, t), link(n + n,n ^ t ^ 1);
		}
	} else {
		puts("No");
	}
}
