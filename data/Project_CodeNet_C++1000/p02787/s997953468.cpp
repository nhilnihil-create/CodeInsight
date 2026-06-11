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
    ll h, n;
    cin >> h >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) cin >> a[i] >> b[i];
    ll dp[20010];  //dp[i]:=体力をi減らすのに必要な魔力のmin
    for (ll i = 0; i < 20010; i++) dp[i] = INF;
    dp[0] = 0;
    for (ll i = 0; i < 20010; i++) {
        for (ll j = 0; j < n;j++){
            if (i - a[j] >= 0) chmin(dp[i], dp[i - a[j]] + b[j]);
        }
    }
    ll ans = INF;
    for (ll i = h; i < 20010; i++) chmin(ans, dp[i]);
    cout << ans << endl;
}