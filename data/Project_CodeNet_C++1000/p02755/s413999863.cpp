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
	int a, b; cin >> a >> b;
	for(int i=1;i<=1300;i++){
		int c = i*0.08;
		int d = i*0.1;
		if(c==a && d==b){
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}