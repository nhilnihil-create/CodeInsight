#include "bits/stdc++.h"
using namespace std;

//34
typedef long long ll;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> val(1e5 + 100);
	int mod = 1e9 + 7;
	for (int i = 0; i < k; ++i){
		int x ;
		cin >> x;
		val[x] = 1;
	}
	vector<ll> v(n + 1);
	if (!val[0])
		v[0] = 1;
	if (!val[1])
		v[1] = 1;
    for (int i = 2; i <= n; ++i) {
		if (!val[i])
			v[i] = (v[i - 1] + v[i - 2]) % mod;
	}
	cout << v[n];
}
