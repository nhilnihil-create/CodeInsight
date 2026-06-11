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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i] / 2;
    }
    ll least = 1;
    for (ll i = 0; i < n;i++){
        least = lcm(least, b[i]);
    }
    map<ll, ll> mp;
    for (ll i = 0; i < n;i++){
        ll cnt = 0;
        while (b[i] % 2 == 0) {
            cnt++;
            b[i] /= 2;
        }
        mp[cnt]++;
    }
    if (mp.size() != 1)
        cout << 0 << endl;
    else{
        cout << ((m/least)+1)/2 << endl;
    }
}