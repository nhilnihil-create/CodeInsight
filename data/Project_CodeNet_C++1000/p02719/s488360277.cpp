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
	ll n,k;
	cin >> n >> k;

	n = n % k;

	while (1) {
		ll a = abs(n-k);
		if (a >= n) {
			cout << n << endl;
			return 0;
		}
		n = a;
	}

	
	return 0;
}