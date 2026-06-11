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
void factorization(long long n,map<long long ,long long>& mp){
    for(long long i=2;i*i<=n;i++){
        while(n%i==0){
            mp[i]++;
            n /= i;
        }
     }
     if(!(n == 1)) mp[n]++;
}
vector<long long> divisor(long long n){
    vector<long long> res;
    for(long long i = 1; i * i <= n; i++) {
        if(n%i==0){
            res.push_back(i);
            if (!(i * i == n)) res.push_back(n / i);
        }
    }
    return res;
}
int main(){
    ll n;
    cin >> n;
    vector<ll> mp1 = divisor(n - 1);
    ll ans = 0;
    ans += mp1.size() - 1;
    vector<ll> mp2 = divisor(n);
	for(auto i:mp2){
        if (i == 1) continue;
        ll tmp = n;
        while (tmp % i == 0) tmp /= i;
        if (tmp % i == 1) ans++;
    }
    cout << ans << endl;
}