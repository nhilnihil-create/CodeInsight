#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using G = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;

ll GCD(ll x, ll y){
	return y ? GCD(y, x%y) : x;	
}

int main() {
	ll n, k, s; cin >> n >> k >> s;
	if(s<1000000000){
		for(ll i=0;i<k;i++){
			cout << s << ' ';
		}
		for(ll i=k;i<n;i++){
			cout << s+1 << ' ';
		}
		cout << endl;
		return 0;
	}else{
		for(ll i=0;i<k;i++){
			cout << s << ' ';
		}
		for(ll i=k;i<n;i++){
			cout << 1 << ' ';
		}
		cout << endl;
		return 0;
	}
	return 0;
}