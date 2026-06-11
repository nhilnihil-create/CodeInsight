#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <cmath>
#include <stdlib.h>

using namespace std;

#define int long long
#define endl "\n"
#define all(v)  v.begin(),v.end()
#define fir first
#define sec second
#define m_p make_pair
#define m_t make_tuple
#define rep(i,n)  for(int i=0; i<(int) (n); i++)


const double pai = 3.1415926535897;
const int mod = 1000000007;
const int INF = 2000000015;
const int MAX = 510000;
const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];


int jousu(int x00, int y00) {
	int z00 = 1;
	for (int i = 0; i < y00; i++) {
		z00 *= x00;
	}
	return z00;
}
int keta(int x00) {
	int z00 = x00;
	int w00 = 0;
	while (z00 != 0) {
		z00 /= 10;
		w00++;
	}
	return w00;
}
int krag(double xx) {
	return INF - (int)(INF - xx);
}
//x未満の要素数を返す二分探索関数
int b_s(vector<int>& vec, int xx) {
	int t = -1;
	int f = vec.size();
	while (f - t > 1) {
		int m = (t + f) / 2;
		if (vec[m] < xx) {
			t = m;
		}
		else {
			f = m;
		}
	}
	return f;
}
template<typename T>
void vecout(vector<T>& vec) { for (T t : vec) cout << t << " "; cout << endl; }
template<typename TT>
void vecin(vector<TT>& vec) { 
	for (int i = 0; i < vec.size(); i++) {
		cin >> vec[i];
	}
}


// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}
//n個を1個以上のx組のグループに分ける重複組み合わせはcom(n-1,x-1)
//グループが0個でもいいときはnにxを足す
// 二項係数計算
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int modinv(int a, int m) {
	int b = m, u = 1, v = 0;
	while (b) {
		int t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
int modpow(int a, int n) {
	int res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

int gcd(int xx, int yy) {
	int p = xx;
	int q = yy;
	if (q > p)swap(p, q);
	while (p % q != 0) {
		p %= q;
		swap(p, q);
	}
	return q;
}
int lcm(int xx, int yy) {
	return xx * yy / gcd(xx, yy);
}
bool prime(int xx) {
	if (xx == 1) {
		return 0;
	}
	for (int i = 2; i * i <= xx; i++) {
		if (xx % i == 0) {
			return 0;
		}
	}
	return 1;
}




signed main() {
	int n, m,a,b,c,d;
	cin >> n >> m;
	d = (int)2 << n-1;
	vector<vector<int>>vec(m+1, vector<int>(d,INF));//DP[i][j] iはi番目までの鍵で何を開けられるか jは値段の最小値
	vector<int>vec2(m),vec3(m);
	rep(i, m) {
		int t = 0;
		cin >> a >> b;
		vec2[i] = a;
		rep(j, b) {
			cin >> c;
			c--;
			t += (int)1 << c;
		}
		vec3[i] = t;
	}
	vec[0][0] = 0;
	for(int i=1; i<=m; i++) {
		rep(j, d) {
			if (vec[i-1][j] == INF) {
				continue;
			}
			vec[i][j | vec3[i-1]] = min(vec[i][j | vec3[i-1]], vec[i-1][j] + vec2[i-1]);
			vec[i][j] = min(vec[i - 1][j], vec[i][j]);
		}
	}
	if (vec[m][d - 1] == INF) {
		cout << -1 << endl;
		return 0;
	}
	cout << vec[m][d - 1];
}
