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
    vector<ll> a(n + 1), b(n+1,0);
    for (ll i = 1; i < n + 1; i++) cin >> a[i];
    for (ll i = n; i > 0;i--){
        ll tmp = 0;
        for (ll j = 2*i; j < n + 1; j += i) tmp += b[j];
        if (tmp % 2 == a[i])
            b[i] = 0;
        else
            b[i] = 1;
    }
    cout << count(b.begin(), b.end(), 1) << endl;
    vector<ll> ans;
    for (ll i = 1; i < n + 1;i++)
        if (b[i]) ans.push_back(i);
    for (ll i = 0; i < ans.size(); i++) cout << ans[i] << " \n"[i == ans.size() - 1];
}