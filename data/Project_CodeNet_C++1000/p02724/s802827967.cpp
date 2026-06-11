#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;

void swap(int a,int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main(void) {
	ll x;
	cin >> x;
	ll ans = 0;

	if (x>=500) {
		ll a = x / 500;
		ans += 1000*a;
		x-=500*a;
	}

	if (x >= 5) {
		ll a = x / 5;
		ans += 5 * a;
	}


	
	cout << ans << endl;
	


	

	return 0;
}