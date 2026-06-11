#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const ll dx[4] = { 0, -1, 1, 0 };
const ll dy[4] = { -1, 0, 0, 1 };
const ll INF = 1e9 + 7;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
void mul(ll a, ll b) {
	a = a * b % INF;
}
using Graph = vector<vector<int>>;
ll mypow(ll x, ll n, ll m) {
	if (n == 0) {
		return 1;
	}
	if (n % 2 == 0) {
		return mypow(x*x%m, n / 2, m);
	}
	else {
		return x * mypow(x, n - 1, m) % m;
	}
}
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
const int MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];
//テーブルをつくる前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;//mod pにおける1,2,,,nの逆元
	for (int i = 2; i < MAX; ++i) {
		fac[i] = fac[i - 1] * i%INF;
		inv[i] = INF - inv[INF%i] * (INF / i) % INF;
		finv[i] = finv[i - 1] * inv[i] % INF;
	}
}

ll COM(int n, int k) {
	if (n < k)return 0;
	if (n < 0 || k < 0)return 0;
	return fac[n] * (finv[k] * finv[n - k] % INF) % INF;
}
///////////////////////////////////////

//期間内に働く日数を最大化するには前から貪欲に働く日を決めるのが最適
//したがって前から貪欲に働く日を決めた場合を考えることでx回目に働く日はL[x]日目以降
//という配列Lを求めることができる
//同様に後ろから貪欲に働く日を決めた場合を考えることでx回目に働く日はR[x]日目以前
//という配列を作ることができる
//i日目に必ず働くのはL[x]=R[x]=iとなるxが存在するときに限る
int L[200010];
int R[200010];
int main() {
	int N, K, C;
	string S;
	cin >> N >> K >> C;
	cin >> S;
	int cnt = 1;
	int now = 0;
	while (cnt <= K) {
		if (S[now] == 'o') {
			L[cnt] = now;
			cnt++;
			now += C+1;
		}
		else {
			now++;
		}
	}
	int cnt2 = K;
	int now2 = N - 1;
	while (cnt2 > 0) {
		if (S[now2] == 'o') {
			R[cnt2] = now2;
			now2 -= (C + 1);
			cnt2--;
		}
		else {
			now2--;
		}
	}
	vector<int>ans;
	for (int i = 1; i <= K; ++i) {
		if (L[i] == R[i]) {
			ans.push_back(L[i]+1);
		}
	}
	if (ans.size() != 0) {
		REP(i, ans.size()) {
			cout << ans[i] << endl;
		}
	}
	return 0;
}
