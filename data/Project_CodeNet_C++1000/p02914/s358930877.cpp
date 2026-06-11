#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
#include<sstream>
#include<cstdio>
#include<cmath>
#include<climits>
#include<cstdlib>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template<class T>
inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i,j,k) for(int i = (int)j;i <= (int)k;i ++)
//const ll mod = 1000000007;
typedef long long ll;
int N;
const int maxn = 1e5 + 5;

ll aa[maxn], a[maxn],p[maxn];
void solve() {
	//cout.precision(10);
	cin >> N;
	ll xsum = 0;
	ll ans = 0; ll tmp = 0;
	rep(i, 1, N)cin >> aa[i], xsum ^= aa[i];
	for (int j = 62; j >= 0; j--) {//remove 0s
		if ((xsum >> j)&1)tmp += 1ll << j;
		else {
			for (int i = 1; i <= N; i++)if ((aa[i] >> j) & 1)
				//a[i] = a[i]*2+1;
				a[i] |= 1ll << j;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 62; j >= 0; j--) {
			if (!(a[i] >> j)) continue;//对线性基的这一位没有贡献
			if (!p[j]) { p[j] = a[i]; break; }//选入线性基中
			a[i] ^= p[j];
		}
	}
	for (int i = 62; i >= 0; i--) if ((ans^p[i])>ans) ans = ans ^ p[i];//从线性基中得到最大值
	ans *= 2;
	ans += tmp;
	cout << ans << endl;
	return;
}

int main() {
	solve();
	cin >> N;
	return 0;
}
