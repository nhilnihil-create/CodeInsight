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
	int s, w; cin >> s >> w;
	if(w>=s){
		cout << "unsafe" << endl;
		return 0;
	}else{
		cout << "safe" << endl;
	}
	return 0;
}