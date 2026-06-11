#include <bits/stdc++.h>
#define uint unsigned int
#define ll long long
using namespace std;

ll attack(ll h) {
	if (h == 1) return 1;
	else return 1 + attack(h/2) * 2;
}

int main() {
	
	ll H; cin >> H;
	cout << attack(H);

	return 0;
}