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
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> ans(n, 0);
    ll tmp = 1;
    for (ll i = 1; i < n;i++){
        if (s[i] == 'R') tmp++;
		else{
            ans[i] += tmp / 2;
            ans[i - 1] += (tmp + 1) / 2;
            tmp = 0;
        }
    }
    tmp = 1;
    for (ll i = n - 2; i >= 0; i--){
        if (s[i] == 'L') tmp++;
		else{
            ans[i] += tmp / 2;
            ans[i + 1] += (tmp + 1) / 2;
            tmp = 0;
        }
    }
    for (ll i = 0; i < n;i++){
        cout << ans[i] << " \n"[i == n - 1];
    }
}