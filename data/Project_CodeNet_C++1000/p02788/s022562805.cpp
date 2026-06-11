#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) cout << fixed << setprecision(x)
const ll inf = LLONG_MAX;
const long double pi = acos(-1);
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

//二分探索
//main関数で呼び出す前に，l, rの一方が条件を満たし他方が満たさないことを確認すること
//配列を引数にするときは原則として参照渡しすること
long long bs(long long l, long long r, ll d, vector<vll> &v, ll i) {
	if (l + 1 == r) {
		if (v[l][0] - v[i][0] > 2 * d) return l;
		else return r;
	}

	long long mid = (l + r) / 2;
	if (v[mid][0] - v[i][0] > 2 * d) return bs(l, mid, d, v, i);
	else return bs(mid, r, d, v, i);
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);

	ll n, d, a;
	cin >> n >> d >> a;
	vector<vll> v(n, vll(2));
	for (ll i = 0; i < n; i++) cin >> v[i][0] >> v[i][1];
	sort(all(v));

	ll ans = 0;
	vll imos(n, 0);
	for (ll i = 0; i < n; i++) {
		if (i > 0) imos[i] += imos[i - 1];
		if (v[i][1] <= imos[i]) continue;
		ll x = ceil((double)(v[i][1] - imos[i]) / a);
		ans += x;
		imos[i] += a * x;
		if (v[n - 1][0] - v[i][0] <= 2 * d) continue;
		ll y = bs(i, n - 1, d, v, i);
		imos[y] -= a * x;
	}
	cout << ans << endl;
}
