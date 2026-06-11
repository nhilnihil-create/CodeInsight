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
    vector<pair<ll, ll>> ww(n);
    for (ll i = 0; i < n;i++){
        ll a, b;
        cin >> a >> b;
        ww[i].first = b;
        ww[i].second = a;
    }
    sort(ww.begin(), ww.end());
    ll cum = 0;
    for (ll i = 0; i< n;i++){
        cum += ww[i].second;
		if(cum>ww[i].first){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}