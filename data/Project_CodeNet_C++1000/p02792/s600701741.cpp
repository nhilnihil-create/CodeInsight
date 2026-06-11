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
long long digits(long long n){
    long long result = 0;
    while(n > 0) {
        result++;
        n /= 10;
    }
    return result;
}
int main(){
ll n;
cin >> n;
vector<vector<ll>> num(10, vector<ll>(10, 0));
for (ll i = 1; i <= n;i++){
    ll bottom = i % 10;
    ll top = i / pow(10,digits(i)-1);
    num[top][bottom]++;
}
ll ans = 0;
for (ll i = 1; i < 10; i++) {
    for (ll j = 1; j < 10;j++){
        ans += num[i][j] * num[j][i];
    }
}
cout << ans << endl;
}