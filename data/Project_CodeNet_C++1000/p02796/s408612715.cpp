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
    vector<pair<ll, ll>> range(n);//(end,begin)
    for (ll i = 0; i < n;i++){
        ll x, l;
        cin >> x >> l;
        range[i].first = x + l;
        range[i].second = x - l;
    }
    sort(range.begin(), range.end());
    ll ans = 0;
    ll now = -INF;
    for (ll i = 0; i < n; i++) {
		if(now<=range[i].second){
            ans++;
            now = range[i].first;
        }
    }
    cout << ans << endl;
}