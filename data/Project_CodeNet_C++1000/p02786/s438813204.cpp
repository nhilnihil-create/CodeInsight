#include "bits/stdc++.h"
using namespace std;
const long long INF = (long long)(1e18) + 1;

long long f(long long hp) {
	if (1 == hp){
		return 1;
	}
	return 2 * f(hp/2) +1;
}
int main() {
	long long H;
	cin >> H;
	cout << f(H) <<endl;
	return 0;
}