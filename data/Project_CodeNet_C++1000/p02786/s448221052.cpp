#include"bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
	ll h;
	cin >> h;
	ll count = 0;
	ll t = 1;

	while(h!=1) {
		h /= 2;
		count += t;
		t *= 2;
	}

	cout << count+t << endl;

	return 0;
}