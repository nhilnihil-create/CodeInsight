#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define rep(i,n) for(int i = 0;i < (n); i++)

int main() {
	ll n;
	ll buf;
	int i, j, k;
	int count = 0;
	cin >> n;
	buf = pow(n, 0.5);
	for (i = 2; i <= buf;i++) {
		if (n == 1)break;
		j = 0;
		while (n % i == 0) {
			n /= i;
			j++;
		}
		k = 1;
		while (j >= k) {
			count++;
			j -= k;
			k++;
		}
	}
	if (n != 1)count++;
	cout << count << endl;
	return 0;
}