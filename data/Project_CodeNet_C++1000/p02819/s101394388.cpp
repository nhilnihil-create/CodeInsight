#include "bits/stdc++.h"

#define rep(i,n) for(int i = 0;i<n;i++)
#define vv(Type,Name, n,m,d)vector<vector<Type>> vv(n, vector<Type>(m, d));

using namespace std;
using ll = long long;


bool is_prime(int a) {
	if (a == 1) return false;

	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) return false;
	}
	return true;
}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	
	int n; cin >> n;
	
	while (true) {
		if (is_prime(n)) {
			cout << n << endl;
			return 0;
		}
		n++;
	}


	return 0;
}
