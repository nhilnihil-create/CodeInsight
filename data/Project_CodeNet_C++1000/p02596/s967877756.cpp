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
	int k;
	cin >> k;
	int x = 7 % k;
	for (int i = 0; i < k; i++) {
		if (x == 0) {
			cout << i + 1;
			return 0;
		}
		x = (x * 10 + 7) % k;
	}
	cout << -1;
	


	return 0;
}
