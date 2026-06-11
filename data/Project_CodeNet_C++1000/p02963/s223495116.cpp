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
#define rep(i,a,n) for(ll i=(a);i<(n);i++)
#define ll long long
#define llint long long int
#define reverse(v)  reverse(v.begin(), v.end());
#define Yes(ans) if(ans)cout<<"Yes"<<endl; else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define hei(a) vector<a>
#define whei(a) vector<vector<a>>
#define UF  UnionFind 
#define Pint pair<int,int>
#define keta(a)  fixed << setprecision(a)
constexpr auto INF = 100000000000;
constexpr auto mod = 1000000007;
//辞書順はnext_permutation( begin( v ), end( v ) );やで！
struct edge { int to, cost; };
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
ll int c(ll int a, ll int b, ll int m) {
	ll int ans = 1;
	for (ll int i = 0; i < b; i++) {
		ans *= a - i;
		ans %= m;
	}
	for (ll int i = 1; i <= b; i++) {
		ans *= modinv(i, m);
		ans %= m;
	}
	return ans;
}

//sは初めの点、vは頂点size、dは最短距離を求める(初期化はINF),Gは有向グラフ
void dijkdtra(int s, int v, vector<int>& d, whei(edge)& G) {
	priority_queue<Pint, vector<Pint>, greater<Pint>> que;//firstが距離、secondが頂点
	d[s] = 0;//スタートの距離はもちろんzero
	que.push(Pint(0, s));
	while (!que.empty()) {
		Pint p = que.top();
		que.pop();
		int V = p.second;
		if (d[V] < p.first)continue;
		for (int i = 0; i < G[V].size(); i++) {
			edge e = G[V][i];
			if (d[e.to] > d[V] + e.cost) {
				d[e.to] = d[V] + e.cost;
				que.push(Pint(d[e.to], e.to));
			}
		}
	}
}



int main() {
	ll s;
	cin >> s;
	const int a = 1000000000;
	ll x = (a - (s % a)) % a;
	ll y = (s + x) / a;
	cout << "0 0 1000000000 1 " << x << " " << y << endl;
	return 0;
}