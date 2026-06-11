#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include<numeric>
#include<list>
#include<cmath>
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0])
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

using namespace std;
typedef long long ll;



int main(void) {
	int n;
	ll D;
	int count = 0;
	cin >> n>>D;
	vector<ll> x(n),y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		if ((x[i] * x[i]) + (y[i] * y[i]) <= D * D) {
			count++;
		}

	}

	cout << count;

	return 0;
}
