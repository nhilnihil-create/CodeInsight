#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <vector>
#include <list>
#include <queue>
#include <stack>

using namespace std;


int main() {
	long long int a[2],b[2];
	cin >> a[0] >> a[1] >> b[0] >> b[1];
	long long int maxi = -1000000000000000000;
	for (long long int i = 0; i <= 1; i++) {
		for (long long int j = 0; j <= 1; j++) {
			maxi = max(a[i] * b[j], maxi);
		}
	}
	cout << maxi;


	return 0;
}
