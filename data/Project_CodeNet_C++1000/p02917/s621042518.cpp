#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;
	long int B[100];

	for (int i = 0; i < N-1 ; ++i) {
		cin >> B[i];
		//cout << B[i] << endl;
	}

	int ans = 0;
	ans += B[0];

	for (int i = 1; i < N-1; ++i) {
		int v = min(B[i - 1], B[i]);
		//cout << "v = " << v << endl;
		ans += v;
	}
	ans += B[N - 2];
	cout << ans << endl;
}