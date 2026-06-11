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
ll n,m;
cin >> n >> m;
vector<ll> a(n);
for (ll i = 0; i < n; i++) cin >> a[i];
priority_queue<ll, vector<ll>> pq;
for (ll i = 0; i < n;i++){
    pq.push(a[i]);
}
while(m--){
    ll t=pq.top();
    pq.pop();
    pq.push(t / 2);
}
ll ans = 0;
while(!pq.empty()){
	ans+=pq.top();
    pq.pop();
}
cout << ans << endl;
}