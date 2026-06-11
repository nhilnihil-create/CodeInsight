#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<string.h>
#include<complex>
#include<math.h>
#include<queue>
#include <functional>
#include<time.h>
#include <stack>
#include<iomanip>
using namespace std;
#define rep(i,a,n) for(llint i=(a);i<(n);i++)
#define ll long long
#define llint long long int
#define reverse(v)  reverse(v.begin(), v.end());
#define Yes(ans) if(ans)cout<<"Yes"<<endl; else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define hei(a) vector<a>
#define whei(a) vector<vector<a>>
#define UF  UnionFind 
#define Pint pair<int,int>
#define Pll pair<llint,llint>
#define keta(a)  fixed << setprecision(a)
const ll mod = 1000000007;
//辞書順はnext_permutation( begin( v ), end( v ) );やで！
const ll INF = 1000000000;

long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

// mod. m での a の逆元 a^{-1} を計算するよ！
long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}


//aCbをmod.mで割った余りを求める
llint C(llint n, llint r, llint m) {
	llint ans = 1;
	for (llint i = 0; i < r; i++) {
		ans *= n - i;
		ans %= m;
	}
	for (llint i = 1; i <= r; i++) {
		ans *= modinv(i, m);
		ans %= m;
	}
	return ans;
}


int main() {
	int n;
	cin >> n;
	vector<queue<int>> que(n);
	whei(int) a(n, hei(int)(n - 1));
	rep(i, 0, n) {
		rep(j, 0, n - 1) {
			cin >> a[i][j];
			a[i][j]--;
			que[i].push(a[i][j]);
		}
	}
	bool x = true;
	int ans = 0;
	while (x) {
		ans++;
		hei(bool) y(n, false);
		x = false;
		rep(i, 0, n) {
			if (que[i].empty()||y[i])continue;
			int v = que[i].front();
			if (!y[v]&&i==que[v].front()) {
				que[i].pop();
				que[v].pop();
				y[i] = true;
				y[v] = true;
				x = true;
			}
		}
		if (x==false) {
			rep(i, 0, n) {
				if (!que[i].empty()) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}
	ans--;
	cout << ans << endl;
    return 0;
}