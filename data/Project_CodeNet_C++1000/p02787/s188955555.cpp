#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<cmath>
#include<numeric>
#include<iomanip>
#include<functional>
#include<cstdlib>
#include<queue>
#include<deque>
#include <iterator>     // std::back_inserter
const double PI = acos(-1);
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
using ll =long long;
const int mod = 1000000007;
const ll inf = 1e18+1;
int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

ll gcd(ll a, ll b) {
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b, a % b);
	}
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
};
//fixed << setprecision(2)
template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
//小文字=大文字+32
int main() {
	int n, h; 	cin >> h >> n;
	vector<ll>a(n), b(n); rep(i, n)cin >> a[i] >> b[i];
	vector<ll>dp(1e4*2+1,inf);//添え字は与えるダメージ
	dp[0] = 0;
	rep(i, n) {
		rep(j, 1e4 *2+1) {
			if (a[i] <= j) {
				chmin(dp[j], dp[j - a[i]]+b[i]);
			}
		}
	}
	ll ans=inf;
	for (int i = h; i < 1e4 * 2 + 1;i++) {
		chmin(ans,dp[i]);
	}
	cout << ans;
}
