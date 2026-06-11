#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long X, K, D;

int main() {
	cin >> X >> K >> D;
	if ((1LL << 60) / K <= D || abs(X) <= D * K) {
		long long V = abs(X) / D;
		if (V % 2 == K % 2) cout << abs(X) % D << endl;
		else cout << abs(D - abs(X) % D) << endl;
	}
	else {
		cout << abs(X) - K * D << endl;
	}
	return 0;
}