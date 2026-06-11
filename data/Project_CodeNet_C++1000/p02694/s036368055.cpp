#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define rep(i,n) for(int i = 0;i < (n); i++)

int main() {
	ll x;
	cin >> x;
	ll a = 100;
	ll count = 0;
	while (a < x) {
		count++;
		a += a / 100;
	}
	cout << count << endl;
	return 0;
}
