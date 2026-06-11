#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<ll> divisor(ll n){
	vector<ll> res;
	for(ll i = 1; i*i <= n; i++){
		if(n%i == 0){
			res.push_back(i);
			if(i != n/i) res.push_back(n/i);
		}
	}
	return res;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector<ll> div = divisor(n);
	ll ans = 0;
	for(auto k : div){
		if(k == 1) continue;
		ll num = n;
		while(num % k == 0) num /= k;
		num %= k;
		if(num == 1) ++ans;
	}
	ans += divisor(n-1).size() - 1;
	cout << ans << endl;
	return 0;
}