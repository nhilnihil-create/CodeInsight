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
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n), x(n,0);
    for (ll i = 0; i < n; i++) cin >> a[i];
    ll sum = 0;
    for (ll i = 0; i < n; i++) sum += a[i];
    x[0] = sum;
    for (ll i = 1; i < n - 1; i+=2) x[0] -= 2 * a[i];
    for (ll i = 0; i < n - 1; i++) {
        x[i + 1] = 2 * a[i] - x[i];
    }
    for (ll i = 0; i < n; i++) cout << x[i] << " \n"[i == n - 1];
}