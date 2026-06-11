#include <bits/stdc++.h>
using namespace std;
bool isprime(int x) {
	if(x <= 1) return false;
	for(int i = 2; i * i <= x; i++) {
		if(x % i == 0) return false;
	}
	return true;
}
int q, n, ret;
int main() {
	cin >> q;
	while(q--) {
		cin >> n;
		ret += isprime(n);
	}
	cout << ret << endl;
}