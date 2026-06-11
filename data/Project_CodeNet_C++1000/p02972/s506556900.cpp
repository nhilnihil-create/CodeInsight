#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define dump(x)  cout << #x << " = " << (x) << endl;	//debug
#define SZ(x) ((ll)(x).size())
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define ps(s) cout << #s << endl;
#define pv(v) cout << (v) << endl;
#define pvd(v) cout << setprecision(16) << (v) << endl;
#define ALL(a)  (a).begin(),(a).end()
#define RANGE(a, l, r)  (a).begin()+(l),(a).begin()+(r)


int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<bool> res(n + 1);
	FOR(i, 1, n) {
		cin >> a[i];
	}
	RFOR(i, n, 1) {
		bool isodd = false;
		for (ll j = 2*i; j <= n; j += i) {
			if (res[j] & 1)isodd = !isodd;
		}
		res[i] = isodd^a[i];
	}
	int cnt = count(RANGE(res, 1, n + 1), 1);
	pv(cnt);
	if (cnt) {
		FOR(i, 1, n) {
			if(res[i])pv(i)
		}
	}
	return(0);
}