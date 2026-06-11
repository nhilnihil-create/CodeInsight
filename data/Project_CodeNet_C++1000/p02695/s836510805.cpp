#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
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
ll n, m, q;
vector<ll> a, b, c, d;
ll calc(vector<ll> &A) {
    ll res = 0;
    for (ll i = 0; i < q;i++){
        if (A[b[i] - 1] - A[a[i] - 1] == c[i]) res += d[i];
    }
    return res;
}
ll dfs(vector<ll> &A){
    if (A.size() == n) return calc(A);
    ll res = 0;
    ll last;
    if (A.empty()) last = 0;
    else
        last = A.back();
    for (ll i = last; i < m;i++){
        A.push_back(i);
        chmax(res, dfs(A));
        A.pop_back();
    }
    return res;
}
int main() {
cin >> n >> m >> q;
a.resize(q);
b.resize(q);
c.resize(q);
d.resize(q);
vector<ll> A;
for (ll i = 0; i < q; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
cout << dfs(A) << endl;
}
