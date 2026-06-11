#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll n, ll k){
	if(n == 0){
		return 0;
	} else {
		return 1 + f(n/k, k);
	}
}

int main(void){
	ll n, k;
	cin >> n >> k;
	cout << f(n, k) << endl;
	return 0;
}
